/*
2016.8.31
BaekJoon Online Judge
Problem Solving

Seong Joon Seo (ID: jjunCoder)

Problem
#2133
타일 채우기
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> dp;

int solve(int n) {
	int & ref = dp[n];
	if (ref != -1) return ref;
	if (n % 2 != 0) return ref = 0;
	if (n == 0) return ref = 1;
	if (n == 2) return ref = 3;

	int ans = 0;
	for (int i = 1; 2 * i <= n; i++) {
		if (i == 1) ans += 3 * solve(n - 2 * i);
		else ans += 2 * solve(n - 2 * i);
	}
	return ref = ans;
}

int main() {
	int n;
	cin.sync_with_stdio(false);
	cin >> n;
	dp.assign(31, -1);
	cout << solve(n);
	return 0;
}