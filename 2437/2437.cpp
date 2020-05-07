#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int w;
    vector<int> weights;
    for (int i = 0; i < n; i++)
    {
        cin >> w;
        weights.push_back(w);
    }
    sort(weights.begin(), weights.end());
    int maxw = 0;

    for (int i = 0; i < n; i++)
    {
        int w = weights[i];
        if (w > maxw + 1)
            break;
        maxw += w;
    }

    cout << maxw + 1 << endl;
    return 0;
}

/*
1 1 2 3 6 7 30

0을 만들 수 있다. 1을 추가하면 0~1을 만들 수 있다.
0~1 -> +1, 1~2
1~2 -> +2, 1,2,3,4
1~4 -> +3, 1,2,3,4,5,6,7
1~7 -> +6, 1~13
1~13 -> +7, 1~20
1~20 -> +30, 1,2,3, ,,, 20,31,32,...,50 -> 21을 못만든다
1 ~ w 를 만들 수 있다-> k를 추가하면
1 ~ w+k 를 만들 수 있다.
*/
