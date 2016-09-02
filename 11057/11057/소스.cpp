/*
2016.9.2
BaekJoon Online Judge
Problem Solving

Seong Joon Seo (ID: jjunCoder)

Problem
#11057
오르막 수
*/

#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin.sync_with_stdio(false);
	cin >> n;
	vector<vector<int> > dp;
	dp.assign(n, vector<int>(10, 0));
	for (int i = 0; i < 10; i++) {
		dp[0][i] = i+1;
	}
	for (int j = 1; j < n; j++) {
		for (int i = 0; i < 10; i++) {
			if (i == 0) dp[j][i] = 1;
			else dp[j][i] = (dp[j][i - 1] + dp[j - 1][i]) % 10007;
		}
	}
	cout << dp[n - 1][9];
	return 0;
}