#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

// # 2565 전깃줄

bool compare(const pair<int, int> &a, const pair<int, int> &b)
{
    return a.second < b.second;
}

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
    sort(vec.begin(), vec.end(), compare);
    vector<int> LIS;
    LIS.assign(n, 1);
    int lis = -1;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (vec[i] > vec[j] && LIS[j] + 1 > LIS[i])
            {
                LIS[i] = LIS[j] + 1;
            }
        }
        if (lis < LIS[i])
            lis = LIS[i];
    }
    cout << n - lis << endl;
    return 0;
}