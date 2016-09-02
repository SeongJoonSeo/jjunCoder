/*
2016.9.2
BaekJoon Online Judge
Problem Solving

Seong Joon Seo (ID: jjunCoder)

Problem
#1699
제곱수의 합
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

vector<int> dp;
const int INF = 987654321;

int solve(int n) {
	if (n <= 0) return 0;
	if (n == 1) return 1;
	int& ret = dp[n];
	if (ret != -1) return ret;
	int k = (int)floor(sqrt(n));
	ret = INF;
	for (int i = k; i >= 1; i--)
		ret = min(ret, solve(n - i*i) + 1);
	return ret;
}

int main() {
	int n;
	cin.sync_with_stdio(false);
	cin >> n;
	dp.assign(n + 1, -1);
	cout << solve(n);
	return 0;
}