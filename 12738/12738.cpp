#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int a, N;
    cin >> N;
    vector<int> vec, LIS;
    for (int i = 0; i < N; i++)
    {
        cin >> a;
        vec.push_back(a);
    }
    LIS.push_back(vec[0]);
    int lis = 0;
    for (int i = 1; i < N; i++)
    {
        if (vec[i] > LIS[lis])
        {
            LIS.push_back(vec[i]);
            lis++;
        }
        else
        {
            auto it = lower_bound(LIS.begin(), LIS.end(), vec[i]);
            *it = vec[i];
        }
    }
    cout << lis + 1 << endl;
    return 0;
}