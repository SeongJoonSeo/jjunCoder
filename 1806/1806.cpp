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
    int n, s, sum = 0;
    cin >> n >> s;
    vector<int> vec(n), psum(n);
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
        sum += vec[i];
        psum[i] = sum;
    }
    int left = 0;
    int minL = 987654321;
    for (int right = 0; right < n; right++)
    {
        if (left == 0)
        {
            if (psum[right] >= s)
            {
                minL = min(minL, right + 1);
                left++;
            }
            else
                continue;
        }

        while (psum[right] - psum[left - 1] >= s)
        {
            minL = min(minL, right - left + 1);
            left++;
            if (left >= psum.size())
                break;
        }
    }
    if (minL == 987654321)
        cout << 0 << endl;
    else
        cout << minL << endl;
    return 0;
}