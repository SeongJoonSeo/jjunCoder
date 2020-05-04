#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

// # 1365 꼬인 전깃줄

int main()
{
    int n;
    cin >> n;
    int m;
    vector<int> vec;
    for (int i = 0; i < n; i++)
    {
        cin >> m;
        vec.push_back(m);
    }

    vector<int> LIS;
    int idx = 0;
    LIS.push_back(vec[idx]);
    for (int i = 1; i < n; i++)
    {
        int num = vec[i];
        if (num > LIS[idx])
        {
            LIS.push_back(num);
            idx++;
        }
        else
        {
            auto it = lower_bound(LIS.begin(), LIS.end(), num);
            *it = num;
        }
    }
    cout << n - (idx + 1) << endl;
    return 0;
}