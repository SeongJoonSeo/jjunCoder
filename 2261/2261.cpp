// BOJ 2261번:
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <cmath>

using namespace std;

#define X first
#define Y second
typedef pair<int, int> II;

int dist(II p1, II p2)
{
    return sqrt((p1.X - p2.X) * (p1.X - p2.X) + (p1.Y - p2.Y) * (p1.Y - p2.Y));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, x, y;
    cin >> n;
    vector<II> vec;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        vec.push_back({x, y});
    }
    sort(vec.begin(), vec.end());
    II p1 = {vec[0].X, vec[0].Y};
    II p2 = {vec[1].X, vec[1].Y};

    int minDist = dist(p1, p2);

    for (int i = 1; i < vec.size(); i++)
    {
        int right = i + 1;
    }
    return 0;
}