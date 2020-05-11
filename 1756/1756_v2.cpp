#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <deque>

using namespace std;

vector<int> dvec;

int D, N;

int main()
{
    scanf("%d %d", &D, &N);
    int d, p;
    vector<int> minD;
    int min_d = 987654321;
    for (int i = 0; i < D; i++)
    {
        scanf("%d", &d);
        dvec.push_back(d);
        if (min_d >= d)
        {
            min_d = d;
            minD.push_back(min_d);
        }
        else
        {
            minD.push_back(min_d);
        }
    }

    int next = true;
    for (int i = D - 1; i >= 0; i--)
    {
        if (next && N > 0)
        {
            scanf("%d", &p);
        }
        if (p <= minD[i])
        {
            N--;
            if (N <= 0)
            {
                cout << i + 1 << endl;
                return 0;
            }
            next = true;
        }
        else
        {
            next = false;
        }
    }

    cout << 0 << endl;
    return 0;
}
