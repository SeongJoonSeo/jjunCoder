// BOJ 2616번:소형기관차
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

    int n, m;
    cin >> n;
    vector<int> vec(n), psum(n, 0);
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
        sum += vec[i];
        psum[i] = sum;
    }
    cin >> m;

    int totsum = -1;
    for (int l1 = 0; l1 + m <= n - m - m; l1++)
    {
        int r1 = l1 + m;
        int sum1 = 0;
        if (l1 == 0)
            sum1 = psum[r1 - 1];
        else
            sum1 = psum[r1 - 1] - psum[l1 - 1];
        for (int l2 = r1; l2 + m <= n - m; l2++)
        {
            int r2 = l2 + m;
            int sum2 = psum[r2 - 1] - psum[l2 - 1];
            for (int l3 = r2; l3 + m <= n; l3++)
            {
                int r3 = l3 + m;
                int sum3 = psum[r3 - 1] - psum[l3 - 1];
                totsum = max(totsum, sum1 + sum2 + sum3);
            }
        }
    }
    cout << totsum << endl;
    return 0;
}