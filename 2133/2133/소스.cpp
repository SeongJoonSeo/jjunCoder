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
	if (n % 2 != 0 || n < 0)
		return 0;
	if (n == 0) return 1;
	int& ret = dp[n];
	if (ret != -1) return ret;
	return ret = solve(n - 4) * 2 + solve(n - 2) * 3;
}

int main() {
	int n;
	cin.sync_with_stdio(false);
	cin >> n;
	dp.assign(n + 1, -1);
	cout << solve(n);
	/*for (int i = 1; i <= n; i++)
		cout << i << ": " << solve(i) << endl;*/
	return 0;
}