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

vector<vector<int> > cost, dp;

int main() {
	int n, c;
	cin.sync_with_stdio(false);
	cin >> n;
	cost.assign(n, vector<int>(3, 0));
	dp.assign(n, vector<int>(3, 987654321));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> c;
			cost[i][j] = c;
		}
	}
	for (int i = 0; i < 3; i++)
		dp[0][i] = cost[0][i];
	for (int index = 1; index < n; index++)
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				if (i != j)
					dp[index][i] = min(dp[index][i], dp[index - 1][j] + cost[index][i]);
	int ret = 987654321;
	for (int i = 0; i < 3; i++)
		ret = min(ret, dp[n - 1][i]);
	cout << ret;
	return 0;
}