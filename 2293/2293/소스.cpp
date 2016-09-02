/*
2016.9.2
BaekJoon Online Judge
Problem Solving

Seong Joon Seo (ID: jjunCoder)

Problem
#2293
동전 1
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, k, cost;
	vector<int> costs;
	vector<vector<int> > dp;
	cin.sync_with_stdio(false);
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> cost;
		costs.push_back(cost);
	}
	dp.assign(n, vector<int>(k + 1, 0));
	sort(costs.begin(), costs.end());
	for (int i = 0; i <= k; i++) i%costs[0] == 0 ? dp[0][i] = 1 : dp[0][i] = 0;
	for (int j = 1; j < costs.size(); j++) {
		for (int i = 0; i <= k; i++) {
			if (i < costs[j]) dp[j][i] = dp[j - 1][i];
			else dp[j][i] = dp[j][i - costs[j]] + dp[j - 1][i];
		}
	}
	cout << dp[costs.size() - 1][k];
	return 0;
}