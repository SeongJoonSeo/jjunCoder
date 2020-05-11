#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
vector<pair<int, int>> vec;

bool compare(pair<int, int> &a, pair<int, int> &b)
{
    return a.second < b.second;
}

int main()
{
    int n;
    cin >> n;

    int a, b;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        vec.push_back(make_pair(a, b));
    }
    sort(vec.begin(), vec.end(), compare);
    vector<int> LIS;
    LIS.push_back(vec[0].first);
    for (int i = 1; i < n; i++)
    {
        int target = vec[i].first;
        if (LIS.back() < target)
            LIS.push_back(target);
        else
        {
            auto it = lower_bound(LIS.begin(), LIS.end(), target);
            *it = target;
            P[i] = distance(LIS.begin(), it);
        }
    }
    printf("%d\n", (n - LIS.size()));

    backtrace(n, LIS.size());
    return 0;
}