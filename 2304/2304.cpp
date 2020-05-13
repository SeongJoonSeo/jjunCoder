#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int N, L, h = 0, max_h = -1, max_idx = 0;
    cin >> N;
    vector<int> vec(1001, 0);
    for (int i = 0; i < N; i++)
    {
        cin >> L >> h;
        vec[L] = h;
        if (max_h < h)
        {
            max_h = h;
            max_idx = L;
        }
    }
    int sum = 0;
    int maxH = 0;
    for (int i = 0; i <= max_idx; i++)
    {
        if (vec[i] > maxH)
        {
            maxH = vec[i];
        }
        sum += maxH;
    }
    maxH = 0;
    for (int i = 1000; i > max_idx; i--)
    {
        if (vec[i] > maxH)
        {
            maxH = vec[i];
        }
        sum += maxH;
    }
    cout << sum << endl;
    return 0;
}