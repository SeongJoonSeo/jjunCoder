// BOJ 1184번: 귀농

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

// [r1,c1 ~ r2,c2) 의 면적을 미리 계산해놓는다.
// Space compelxity : 6,765,201 *2 = 12MB
int preCalDown[51][51][51][51], preCalUp[51][51][51][51];
vector<vector<int>> vec, pSumLRUp, pSumLRDown;
int n, result = 0;

void setting();
void solve();
void solveLRUp(int row, int col);
void solveLRDown(int row, int col);
bool isIn(int r, int c) { return 0 <= r && r < n && 0 <= c && c < n; }

int main()
{
    setting();
    solve();
    cout << result << endl;
    return 0;
}

void setting()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    vec.assign(n, vector<int>(n, 0));
    pSumLRUp.assign(n, vector<int>(n, 0));
    pSumLRDown.assign(n, vector<int>(n, 0));

    for (int row = 0; row < n; row++)
    {
        int rowSum = 0;
        for (int col = 0; col < n; col++)
        {
            cin >> vec[row][col];
            rowSum += vec[row][col];
            if (row == 0)
                pSumLRDown[row][col] = rowSum;
            else
                pSumLRDown[row][col] = pSumLRDown[row - 1][col] + rowSum;
        }
    }

    for (int row = n - 1; row >= 0; row--)
    {
        int rowSum = 0;
        for (int col = 0; col < n; col++)
        {
            rowSum += vec[row][col];
            if (row == n - 1)
                pSumLRUp[row][col] = rowSum;
            else
                pSumLRUp[row][col] = pSumLRUp[row + 1][col] + rowSum;
        }
    }

    for (int r1 = 0; r1 < n; r1++)
        for (int c1 = 0; c1 < n; c1++)
            for (int r2 = 0; r2 < n; r2++)
                for (int c2 = 0; c2 < n; c2++)
                {
                    if (r1 == 0 && c1 == 0)
                        preCalDown[r1][c1][r2][c2] = pSumLRDown[r2][c2];
                    else if (r1 == 0)
                        preCalDown[r1][c1][r2][c2] = pSumLRDown[r2][c2] - pSumLRDown[r2][c1 - 1];
                    else if (c1 == 0)
                        preCalDown[r1][c1][r2][c2] = pSumLRDown[r2][c2] - pSumLRDown[r1 - 1][c2];
                    else
                        preCalDown[r1][c1][r2][c2] =
                            pSumLRDown[r2][c2] - pSumLRDown[r2][c1 - 1] -
                            pSumLRDown[r1 - 1][c2] + pSumLRDown[r1 - 1][c1 - 1];
                }

    for (int r1 = n - 1; r1 >= 0; r1--)
        for (int c1 = 0; c1 < n; c1++)
            for (int r2 = n - 1; r2 >= 0; r2--)
                for (int c2 = 0; c2 < n; c2++)
                {
                    if (r1 == n - 1 && c1 == 0)
                        preCalUp[r1][c1][r2][c2] = pSumLRUp[r2][c2];
                    else if (r1 == n - 1)
                        preCalUp[r1][c1][r2][c2] = pSumLRUp[r2][c2] - pSumLRUp[r2][c1 - 1];
                    else if (c1 == 0)
                        preCalUp[r1][c1][r2][c2] = pSumLRUp[r2][c2] - pSumLRUp[r1 + 1][c2];
                    else
                        preCalUp[r1][c1][r2][c2] =
                            pSumLRUp[r2][c2] - pSumLRUp[r2][c1 - 1] -
                            pSumLRUp[r1 + 1][c2] + pSumLRUp[r1 + 1][c1 - 1];
                }
}

void solve()
{
    // 내부의 한 점을 잡고
    // 50 * 50 = 250
    // 250 * 4 * 250 = 250000
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            solveLRUp(row, col);
            solveLRDown(row, col);
        }
    }
}

void solveLRUp(int row, int col)
{
    unordered_map<int, int> check;

    for (int r1 = n - 1; r1 > row; r1--)
    {
        for (int c1 = 0; c1 < col; c1++)
        {
            auto it = check.insert({preCalUp[r1][c1][row + 1][col - 1], 1});
            if (!it.second)
                it.first->second += 1;
        }
    }
    for (int r1 = row; r1 >= 0; r1--)
    {
        for (int c1 = col; c1 < n; c1++)
        {
            auto it = check.find(preCalUp[row][col][r1][c1]);
            if (it != check.end())
                result += it->second;
        }
    }
}

void solveLRDown(int row, int col)
{
    unordered_map<int, int> check;

    for (int r1 = 0; r1 < row; r1++)
        for (int c1 = 0; c1 < col; c1++)
        {
            auto it = check.insert({preCalDown[r1][c1][row - 1][col - 1], 1});
            if (!it.second)
                it.first->second += 1;
        }
    for (int r1 = row; r1 < n; r1++)
        for (int c1 = col; c1 < n; c1++)
        {
            auto it = check.find(preCalDown[row][col][r1][c1]);
            if (it != check.end())
                result += it->second;
        }
}