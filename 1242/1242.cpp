// BOJ 1242번: 소풍
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k, m;
    cin >> n >> k >> m;

    int leftNum = n, pos = m, outPos = k;

    for (int i = 0; i < n; i++) {
        outPos = k % leftNum;
        if (outPos == 0) outPos = leftNum;
        if (leftNum == 1 || pos == outPos) break;
        pos -= outPos;
        if (pos < 0) pos += leftNum;
        leftNum--;
    }
    cout << n - leftNum + 1 << endl;
    return 0;
}