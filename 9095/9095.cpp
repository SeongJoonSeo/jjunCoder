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
    int t, n;
    cin >> t;
    vector<int> dp(11, 0);
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for (int i = 4; i < 11; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }
    while (t--)
    {
        cin >> n;
        cout << dp[n] << endl;
    }
    return 0;
}