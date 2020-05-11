#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
vector<vector<int>> board;
vector<vector<int>> dp;
int n, m;
int dir[4][2] = {
    {-1, 0},
    {1, 0},
    {0, -1},
    {0, 1}};

bool isIn(int r, int c)
{
    return (0 <= r && r < n && 0 <= c && c < m);
}

int dfs(int dest_x, int dest_y)
{
    int &dest = dp[dest_x][dest_y];
    if (dest != -1)
        return dest;
    dest = 0;
    for (int i = 0; i < 4; i++)
    {
        int nx = dest_x + dir[i][0];
        int ny = dest_y + dir[i][1];
        if (!isIn(nx, ny))
            continue;
        if (board[nx][ny] > board[dest_x][dest_y])
            dest += dfs(nx, ny);
    }
    return dest;
}

int main()
{
    cin >> n >> m;
    board.assign(n, vector<int>(m, 0));
    dp.assign(n, vector<int>(m, -1));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> board[i][j];

    dp[0][0] = 1;
    cout << dfs(n - 1, m - 1) << endl;
    return 0;
}