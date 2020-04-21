#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

// 1145번 적어도 대부분의 배수

int GCD(int a, int b)
{
    while (b != 0)
    {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int LCM(int a, int b, int c)
{
    int t = a * b / GCD(a, b);
    return t * c / GCD(t, c);
}

int main()
{
    int a[5];
    int n;
    for (int i = 0; i < 5; i++)
    {
        cin >> n;
        a[i] = n;
    }
    vector<int> v;
    for (int i = 0; i < 5; i++)
    {
        for (int j = i + 1; j < 5; j++)
        {
            for (int k = j + 1; k < 5; k++)
            {
                v.push_back(LCM(a[i], a[j], a[k]));
            }
        }
    }
    sort(v.begin(), v.end());
    cout << v.front() << endl;
    return 0;
}