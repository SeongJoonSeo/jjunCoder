#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
int n, sx, sy, sh, minFatigue, minh, maxh, nk, cnt;
bool success = false;
vector<vector<bool>> visited;
vector<vector<char>> board;
vector<vector<int>> height;
vector<int> h;
int dir[8][2] = {
    {-1, 0},
    {-1, 1},
    {0, 1},
    {1, 1},
    {1, 0},
    {1, -1},
    {0, -1},
    {-1, -1}};

void setting();
void solve();
void dfs(int r, int c);
bool isIn(int r, int c);

int main()
{
    setting();
    solve();
    return 0;
}

void setting()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    board.assign(n, vector<char>(n, 0));
    height.assign(n, vector<int>(n, 0));
    minFatigue = 987654321;
    nk = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 'P')
                sx = i, sy = j;
            else if (board[i][j] == 'K')
                nk++;
        }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            cin >> height[i][j];
            h.push_back(height[i][j]);
            if (i == sx && j == sy)
                sh = height[i][j];
        }
    sort(h.begin(), h.end());
    h.erase(unique(h.begin(), h.end()), h.end());
}

void solve()
{
    int left = 0, right = 0;
    while (true)
    {
        if (left >= h.size() || right >= h.size() || left > right)
            break;
        minh = h[left];
        maxh = h[right];
        if (maxh == 8)
            int abd = 12;

        if (minh <= sh && sh <= maxh)
        {
            success = false;
            cnt = nk;
            visited.assign(n, vector<bool>(n, false));
            dfs(sx, sy);
            if (success)
                left++;
            else
                right++;
        }
        else
        {
            right++;
        }
    }
    cout << minFatigue << endl;
}

void dfs(int r, int c)
{
    visited[r][c] = true;
    if (board[r][c] == 'K')
        cnt--;
    if (cnt == 0)
    {
        // 피로도 차이 구한다
        minFatigue = min(minFatigue, maxh - minh);
        success = true;
        return;
    }

    for (int i = 0; i < 8; i++)
    {
        int nr = r + dir[i][0];
        int nc = c + dir[i][1];
        if (isIn(nr, nc) && !visited[nr][nc])
            if (minh <= height[nr][nc] && height[nr][nc] <= maxh)
                dfs(nr, nc);
    }
}

bool isIn(int r, int c)
{
    return 0 <= r && r < n && 0 <= c && c < n;
}