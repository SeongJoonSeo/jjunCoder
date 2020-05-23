// BOJ 2169번: 로봇 조종하기
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
vector<vector<int>> board, dp, lr, rl;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    board.assign(n, vector<int>(m, 0));
    dp.assign(n, vector<int>(m, -1));
    lr.assign(n, vector<int>(m, 0));
    rl.assign(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> board[i][j];

    dp[0][0] = board[0][0];
    for (int col = 1; col < m; col++)
        dp[0][col] = board[0][col] + dp[0][col - 1];

    for (int row = 1; row < n; row++)
    {
        lr[row][0] = dp[row - 1][0] + board[row][0];
        rl[row][m - 1] = dp[row - 1][m - 1] + board[row][m - 1];
        //left to right
        for (int col = 1; col < m; col++)
            lr[row][col] = max(dp[row - 1][col], lr[row][col - 1]) + board[row][col];
        for (int col = m - 2; col >= 0; col--)
            rl[row][col] = max(dp[row - 1][col], rl[row][col + 1]) + board[row][col];
        for (int col = 0; col < m; col++)
            dp[row][col] = max(lr[row][col], rl[row][col]);
    }
    cout << dp[n - 1][m - 1] << endl;
    return 0;
}