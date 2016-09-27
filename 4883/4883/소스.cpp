/*
2016.9.26
BaekJoon Online Judge
Problem Solving

Seong Joon Seo (ID: jjunCoder)

Problem
#4883
삼각 그래프
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int INF = 987654321;
int main() {
	int n, cost, t = 1;
	cin.sync_with_stdio(false);
	cin >> n;

	while(n) {
		vector<vector<long long> > board;
		vector<vector<long long> > dp;
		board.assign(n, vector<long long>(3, 0));
		dp.assign(n, vector<long long>(3, INF));

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 3; j++) {
				cin >> cost;
				board[i][j] = cost;
			}
		}
		dp[0][0] = INF;
		dp[0][1] = board[0][1];
		dp[0][2] = dp[0][1] + board[0][2];
		for (int i = 1; i < n; i++) {
			for (int j = 0; j < 3; j++) {
				dp[i][j] = dp[i - 1][j] + board[i][j];				
				if (j != 0) {
					dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + board[i][j]);
					dp[i][j] = min(dp[i][j], dp[i][j - 1] + board[i][j]);
				}	
				if (j != 2)
					dp[i][j] = min(dp[i][j], dp[i - 1][j + 1] + board[i][j]);					
			}
		}
		printf("%d. %lld\n", t++, dp[n - 1][1]);
		cin >> n;
	}
	return 0;
}