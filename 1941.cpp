// 1941 소문난 칠공주

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

unordered_set<string> result;

int dir[4][2] = {
    {-1, 0},
    {1, 0},
    {0, -1},
    {0, 1}};

bool isIn(int row, int col)
{
    return (row >= 0 && row < 5) && (col >= 0 && col < 5);
}

void bfs(int s_row, int s_col, char m[][5])
{
    int s_count = 0;
    int count = 0;
    queue<pair<int, int>> q;
    q.push(make_pair(s_row, s_col));

    while (!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();
        int c_row = cur.first;
        int c_col = cur.second;

        if (m[c_row][c_col] == 'S')
            s_count++;
        m[c_row][c_col] = 'x';
        count++;
        if (count == 7)
        {
            if (s_count >= 4)
            {
                string temp = "";
                for (int i = 0; i < 5; i++)
                {
                    for (int j = 0; j < 5; j++)
                    {
                        temp += m[i][j];
                    }
                }
                result.insert(temp);
            }
            return;
        }

        for (int i = 0; i < 4; i++)
        {
            int n_row = c_row + dir[i][0];
            int n_col = c_row + dir[i][1];
            if (isIn(n_row, n_col) && m[n_row][n_col] != 'x')
            {
                q.push(make_pair(n_row, n_col));
            }
        }
    }
}
int solve(char m[][5])
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            bfs(i, j, m);
        }
    }
    return result.size();
}

int main()
{
    // S : 이다솜파
    // Y : 임도연파
    // S가 적어도 4명 이상 포함되어 있어야 한다.
    // 7명 자리가 가로나 세로로 인접해서 소문난 칠공주를 결성할 수 있는 모든 경우의 수를 구하기

    string str;
    char matrix[5][5];

    for (int i = 0; i < 5; i++)
    {
        cin >> str;
        for (int j = 0; j < 5; j++)
        {
            matrix[i][j] = str[j];
        }
    }
    cout << solve(matrix) << endl;
    return 0;
}