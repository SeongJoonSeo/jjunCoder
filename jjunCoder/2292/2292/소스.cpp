/*
2016.8.22
BaekJoon Online Judge
Problem Solving

Seong Joon Seo (ID: jjunCoder)

Problem
#2292
¹úÁý
*/

#include <iostream>

using namespace std;

void solve(long long n,int start, int end) {
	int k = (start + end) / 2;
	if (n <= (3 * k*k + 3 * k + 1) && n > (3 * (k - 1)*(k - 1) + 3 * (k - 1) + 1)) {
		cout << 1 + k;
		return;
	}
	if (n > (3 * k*k + 3 * k + 1))
		solve(n, k + 1, end);
	else if (n <= (3 * (k - 1)*(k - 1) + 3 * (k - 1) + 1))
		solve(n, start, k);
}

int main() {
	long long n;
	cin >> n;
	if (n == 1)
	{
		cout << 1;
		return 0;
	}
	solve(n,1,18257);
	return 0;
}