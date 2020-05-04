#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

// # 1365 꼬인 전깃줄

// lower_bound 직접 구현

int my_lower_bound(int start, int end, const int *LIS, int target)
{
    int left = start;
    int right = end;
    int mid = end;
    while (left < right)
    {
        mid = (left + right) / 2;
        if (target > LIS[mid])
        {
            left = mid + 1;
        }
        else
        {
            right = mid;
        }
    }
    return right;
}

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

    int LIS[100001];
    int idx = 0;
    LIS[idx] = (vec[idx]);
    for (int i = 1; i < n; i++)
    {
        int num = vec[i];
        if (num > LIS[idx])
        {
            LIS[++idx] = (num);
        }
        else
        {
            int ii = my_lower_bound(0, idx + 1, LIS, num);
            LIS[ii] = num;
        }
    }
    cout << n - (idx + 1) << endl;
    return 0;
}

/*
8
10 20 30 20 50 40 45 50
*/