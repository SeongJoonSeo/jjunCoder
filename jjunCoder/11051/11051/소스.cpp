/*
2016.8.26
BaekJoon Online Judge
Problem Solving

Seong Joon Seo (ID: jjunCoder)

Problem
#11051
이항 계수 2
*/

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > dp;

int main() {
	int n, k;
	cin.sync_with_stdio(false);
	cin >> n >> k;
	dp.assign(n + 2, vector<int>(n + 2, -1));
	
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0 || j == i)
				dp[i][j] = 1;
			if (j != 0)
				dp[i + 1][j] = (dp[i][j - 1] + dp[i][j]) % 10007;
		}
	}
	
	cout << dp[n][k];
	return 0;
}