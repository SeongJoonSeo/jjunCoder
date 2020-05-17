// BOJ 2156번: 포도주 시식
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<int> vec(n), dp(n);
    for (int i = 0; i < n; i++)
        cin >> vec[i];

    dp[0] = vec[0];
    if (n == 1)
    {
        cout << dp[0] << endl;
        return 0;
    }

    dp[1] = vec[0] + vec[1];
    if (n == 2)
    {
        cout << dp[1] << endl;
        return 0;
    }

    int maxn = dp[1];
    dp[2] = max(vec[1] + vec[2], vec[0] + vec[2]);
    dp[2] = max(dp[1], dp[2]);
    maxn = max(maxn, dp[2]);
    for (int i = 3; i < n; i++)
    {
        dp[i] = max(dp[i - 3] + vec[i - 1] + vec[i], dp[i - 2] + vec[i]);
        dp[i] = max(dp[i], dp[i - 1]);

        maxn = max(maxn, dp[i]);
    }
    cout << maxn << endl;
    return 0;
}