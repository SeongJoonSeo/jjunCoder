/*
2016.8.30
BaekJoon Online Judge
Problem Solving

Seong Joon Seo (ID: jjunCoder)

Problem
#2579
계단 오르기
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> stair;
vector<vector<int> > dp;

int solve(int n,int step) {
	if (n < 0) return 0;
	int& ret = dp[n][step];
	if (ret != -1) return ret;
	if (n == 0) return ret = stair[0];
	if (step == 1) ret = max(ret, stair[n] + solve(n - 1, 0));
	return ret = max(ret, stair[n] + solve(n - 2, 1));	
}

int main() {	
	int n, cost;
	cin.sync_with_stdio(false);
	cin >> n;
	dp.assign(n, vector<int>(2, -1));
	for (int i = 0; i < n; i++) {
		cin >> cost;
		stair.push_back(cost);
	}
	cout << solve(n - 1, 1);
	return 0;
}