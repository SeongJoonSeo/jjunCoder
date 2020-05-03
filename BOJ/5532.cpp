#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int l, a, b, c, d;
    cin >> l >> a >> b >> c >> d;
    int A, B;
    A = a / c;
    if (a % c != 0)
        A++;
    B = b / d;
    if (b % d != 0)
        B++;
    cout << l - max(A, B) << endl;

    return 0;
}