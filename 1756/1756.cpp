#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
typedef pair<int, int> IPAIR;
vector<IPAIR> dvec, dvec2;
int lastIdx = 0;
bool success = true;

int my_upper_bound(int begin, int end, int target)
{
    int left = begin;
    int right = end;
    int mid = begin;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (dvec[mid].first >= target)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return mid;
}

bool compare1(IPAIR a, IPAIR b)
{
    if (a.first == b.first)
        return a.second > b.second;
    else
        return (a.first < b.first);
}
bool compare2(IPAIR a, IPAIR b)
{
    return a.second < b.second;
}

void solve(int target)
{
    //sort1
    int ii = my_upper_bound(0, dvec.size(), target);
    int idx = dvec[ii].second;
    if (dvec[ii].first < target)
    {
        idx--;
        if (idx < 0)
        {
            // cout << "ERROR" << endl;
            success = false;
            return;
        }
    }

    //sort2, 기준옮기기
    // dvec = vector<IPAIR>(dvec.begin(), dvec.begin() + idx);
    lastIdx = idx + 1;
}

int main()
{
    int D, N;
    scanf("%d %d", &D, &N);
    int d, p;

    for (int i = 0; i < D; i++)
    {
        scanf("%d", &d);
        dvec.push_back(make_pair(d, i));
        dvec2.push_back(make_pair(i, d));
    }
    sort(dvec.begin(), dvec.end(), compare1);
    sort(dvec2.begin(), dvec2.end());

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &p);
        solve(p);
    }
    if (success)
        cout << lastIdx << endl;
    else
        cout << 0 << endl;

    return 0;
}
