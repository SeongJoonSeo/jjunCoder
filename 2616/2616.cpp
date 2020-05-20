// BOJ 2616번:소형기관차
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int n;

bool isIn(int idx)
{
    return 0 <= idx && idx < n;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int m;
    cin >> n;
    vector<int> vec(n + 1), psum(n + 1, 0);
    vector<int> dp[3];
    for (int i = 0; i < 3; i++)
        dp[i].assign(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        cin >> vec[i];
        psum[i] = psum[i - 1] + vec[i];
    }
    cin >> m;

    for (int train_num = 0; train_num < 3; train_num++)
    {
        dp[train_num][0] = vec[0];
    }

    for (int train_num = 0; train_num < 3; train_num++)
    {
        for (int i = 2; i <= n; i++)
        {
            // 지금 소형 기관차 이전의 소형 기관차가
            // i-m번째 화물칸까지 최대로 선택한 수
            // + 지금 소형 기관차가 (i-m+1 ~ i)번째 까지 태운 승객 수
            int prev = 0;
            if (train_num - 1 >= 0 && isIn(i - m))
                prev = dp[train_num - 1][i - m];
            if (isIn(i - m))
                prev += psum[i] - psum[i - m];
            dp[train_num][i] = max(dp[train_num][i - 1], prev);
        }
    }

    cout << dp[2][n] << endl;

    return 0;
}