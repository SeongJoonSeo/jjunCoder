#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> line(n);
    for (int i = 0; i < n; i++)
    {
        cin >> line[i];
    }

    vector<int> LIS(n);
    LIS[0] = line[0];
    int idx = 0;
    for (int i = 1; i < n; i++)
    {
        int target = line[i];
        if (LIS[idx] < target)
            LIS[++idx] = target;
        else
        {
            auto it = lower_bound(LIS.begin(), LIS.begin() + idx, target);
            *it = target;
        }
    }
    cout << n - (idx + 1) << endl;
    return 0;
}

// 3 7 5 2 6 1 4