// #2568 전깃줄 -2 2트

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int, int> II;

int _lower_bound(int start, int end, int target, vector<int> &lis)
{
    int ret = end;
    int left = start;
    int right = end;
    int mid = end;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (lis[mid] >= target)
        {
            ret = min(ret, mid);
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return ret;
}

int main()
{
    int n, a, b;
    scanf("%d", &n);

    vector<II> vec;
    vector<bool> check;
    check.assign(500001, false);

    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &a, &b);
        vec.push_back({a, b});
    }
    sort(vec.begin(), vec.end());
    vector<int> lis;
    vector<II> ans;
    int LIS = 0;
    lis.push_back(vec[0].second);
    ans.push_back({0, vec[0].second});
    for (int i = 1; i < vec.size(); i++)
    {
        int target = vec[i].second;
        if (target > lis.back())
        {
            ans.push_back({LIS + 1, target});
            lis.push_back(target);
            LIS++;
        }
        else
        {
            int idx = _lower_bound(0, lis.size(), target, lis);
            lis[idx] = target;
            ans.push_back({idx, target});
        }
    }
    LIS++;
    printf("%d\n", n - LIS);

    for (int i = ans.size() - 1; i >= 0; i--)
    {
        if (ans[i].first == LIS - 1)
        {
            check[ans[i].second] = true;
            LIS--;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (!check[vec[i].second])
        {
            printf("%d\n", vec[i].first);
        }
    }
    return 0;
}