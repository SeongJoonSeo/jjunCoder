#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long LL;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, a;
    cin >> n;
    vector<LL> vec(n);
    for (int i = 0; i < n; i++)
        cin >> vec[i];
    sort(vec.begin(), vec.end());
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> a;
        if (binary_search(vec.begin(), vec.end(), a))
            cout << 1 << "\n";
        else
            cout << 0 << "\n";
    }
    return 0;
}