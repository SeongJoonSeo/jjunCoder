/*
2016.9.2
BaekJoon Online Judge
Problem Solving

Seong Joon Seo (ID: jjunCoder)

Problem
#1904
01타일
*/

#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	vector<int> dp;
	cin.sync_with_stdio(false);
	cin >> n;
	dp.assign(n + 1, -1);
	dp[0] = 0; dp[1] = 1; dp[2] = 2;
	for (int i = 3; i <= n; i++) {
		dp[i] = dp[i - 2] + dp[i - 1];
		dp[i] %= 15746;
	}
	cout << dp[n];
	return 0;
}