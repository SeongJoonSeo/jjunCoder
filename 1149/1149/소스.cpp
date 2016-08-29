/*
2016.8.29
BaekJoon Online Judge
Problem Solving

Seong Joon Seo (ID: jjunCoder)

Problem
#1149
RGB거리
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int> > cost;
vector<int> dp;

int solve(int index, int prev) {
	int mini = 987654321;
	int& ret = dp[index];
	//base case
	if (index == 0) {
		for (int i = 0; i < 3; i++)
			if (i != prev)
				mini = min(mini, cost[index][i]);
		return ret = mini;
	}
	if (ret != -1)
		return ret;	
	for (int i = 0; i < 3; i++) {
		if (i != prev)
			mini = min(mini, solve(index - 1, i) + cost[index][i]);
	}
	return ret = mini;
}

int main() {
	int n, c;
	cin.sync_with_stdio(false);
	cin >> n;
	cost.assign(n, vector<int>(3, 0));
	dp.assign(n, -1);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> c;
			cost[i][j] = c;
		}
	}
	solve(n - 1, -1);
	cout << dp[n - 1];
	return 0;
}