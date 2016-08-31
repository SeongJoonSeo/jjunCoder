/*
2016.8.31
BaekJoon Online Judge
Problem Solving

Seong Joon Seo (ID: jjunCoder)

Problem
#11726
2*n 타일링
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> dp;

int solve(int n) {
	if (n <= 1) return 1;
	int& ret = dp[n];
	if (ret != -1)return ret;
	return ret = (solve(n - 1) + solve(n - 2)) % 10007;
}

int main() {
	int n;
	cin.sync_with_stdio(false);
	cin >> n;
	dp.assign(n + 1, -1);
	cout << solve(n);
	return 0;
}