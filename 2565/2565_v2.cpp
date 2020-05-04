#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

// # 2565 전깃줄

int main()
{
    int n;
    cin >> n;
    int m, k;
    vector<pair<int, int>> vec;
    for (int i = 0; i < n; i++)
    {
        cin >> m >> k;
        vec.push_back(make_pair(m, k));
    }
    sort(vec.begin(), vec.end());
    vector<int> LIS;
    LIS.assign(n, 0);
    int idx = 0;
    LIS[0] = (vec[idx].second);
    for (int i = 1; i < n; i++)
    {
        int num = vec[i].second;
        if (num > LIS[idx])
        {
            LIS[++idx] = num;
        }
        else
        {
            auto it = lower_bound(LIS.begin(), LIS.begin() + idx, num);
            *it = num;
        }
    }
    cout << n - (idx + 1) << endl;
    return 0;
}