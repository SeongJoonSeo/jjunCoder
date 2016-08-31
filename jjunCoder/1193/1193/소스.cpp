/*
2016.8.22
BaekJoon Online Judge
Problem Solving

Seong Joon Seo (ID: jjunCoder)

Problem
#1193
분수찾기
*/

#include <iostream>

using namespace std;

void solve(long long x,int start, int end) {
	int k = (start + end) / 2, n;
	if (k*(k - 1) / 2 < x&&x <= k*(k + 1) / 2) {
		n = x - (k*(k - 1) / 2);
		if (k % 2 == 0)
			cout << n << "/" << (k - n + 1);
		else
			cout << (k - n + 1) << "/" << n;
	}
	else if (k*(k - 1) / 2 >= x)
		solve(x, start, k);
	else if (x > k*(k + 1) / 2)
		solve(x, k + 1, end);
	return;
}

int main() {
	long long x;
	cin >> x;
	if (x == 1) {
		cout << "1/1";
		return 0;
	}
	else
		solve(x,1,5000);
	return 0;
}