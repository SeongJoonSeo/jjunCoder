/*
2016.9.2
BaekJoon Online Judge
Problem Solving

Seong Joon Seo (ID: jjunCoder)

Problem
#11048
이동하기
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int> > maze, dp;

int main() {
	int n, m, cost;
	cin.sync_with_stdio(false);
	cin >> n >> m;
	maze.assign(n, vector<int>(m, -1));
	dp.assign(n, vector<int>(m, -1));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> cost;
			maze[i][j] = cost;
		}
	}	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i == 0 && j == 0) dp[0][0] = maze[0][0];
			else if (i == 0) dp[i][j] = maze[i][j] + dp[i][j - 1];
			else if (j == 0) dp[i][j] = maze[i][j] + dp[i - 1][j];
			else dp[i][j] = max(max(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + maze[i][j];
		}
	}
	cout << dp[n - 1][m - 1];
	return 0;
}