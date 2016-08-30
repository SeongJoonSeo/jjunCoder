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
vector<int> dp;

int solve(int n,vector<bool> step) {
	if (n < 0)
		return 0;
	if (n == 0)
		return stair[0];
	int& ret = dp[n];
	if (ret != -1) return ret;
	step[n] = true;
	if (n >= 2 && (step[n - 2] && step[n - 1] && step[n]))
		return 0;
	if (n < step.size() - 1 && (step[n - 1] && step[n] && step[n + 1]))
		return 0;
	if (n < step.size() - 2 && (step[n] && step[n + 1] && step[n + 2]))
		return 0;
	int maxi = -1;
	if (n == step.size() - 1)
		maxi = solve(n - 1, step) + stair[n];
	else if (!step[n + 1]) 
		maxi = solve(n - 1, step) + stair[n];
	return ret = max(maxi, solve(n - 2, step) + stair[n]);
}

int main() {	
	int n, cost;
	cin.sync_with_stdio(false);
	cin >> n;
	dp.assign(n, -1);
	vector<bool> step(n, false);
	for (int i = 0; i < n; i++) {
		cin >> cost;
		stair.push_back(cost);
	}
	dp[0] = stair[0];
	cout << solve(n - 1, step);
	return 0;
}