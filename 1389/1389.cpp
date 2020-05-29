// BOJ 1389번: 케빈 베이컨의 6단계 법칙
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

#define INF 987654321

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, a, b;
    cin >> n >> m;
    vector<vector<int>> relationship, dp;
    relationship.assign(n + 1, vector<int>(n + 1, INF));
    dp.assign(n + 1, vector<int>(n + 1, INF));
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        relationship[a][b] = 1;
        relationship[b][a] = 1;
        dp[a][b] = 1;
        dp[b][a] = 1;
    }
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                dp[i][j] = min(dp[i][k] + dp[k][j], dp[i][j]);

    int kavin = INF, sum = 0, minNum = n + 1;
    vector<pair<int, int>> ret;
    for (int i = 1; i <= n; i++)
    {
        sum = 0;
        for (int j = 1; j <= n; j++)
            if (i != j)
                sum += dp[i][j];
        ret.push_back({sum, i});
    }
    sort(ret.begin(), ret.end());

    cout << ret.front().second << endl;
    return 0;
}