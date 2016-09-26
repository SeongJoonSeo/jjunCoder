/*
2016.9.26
BaekJoon Online Judge
Problem Solving

Seong Joon Seo (ID: jjunCoder)

Problem
#10844
쉬운 계단 수
*/

#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin.sync_with_stdio(false);
	cin >> n;
	vector<vector<long long> > dp;
	dp.assign(n + 1, vector<long long>(10, 0));
	for (int i = 1; i < 10; i++)
		dp[1][i] = 1;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < 10; j++) {
			if (j == 0) {
				dp[i + 1][1] += dp[i][j];
				dp[i + 1][1] %= 1000000000;
			}
			else if (j == 9) {
				dp[i + 1][8] += dp[i][j];
				dp[i + 1][8] %= 1000000000;
			}
			else {
				dp[i + 1][j - 1] += dp[i][j];
				dp[i + 1][j - 1] %= 1000000000;
				dp[i + 1][j + 1] += dp[i][j];
				dp[i + 1][j + 1] %= 1000000000;
			}
		}
	}
	long long sum = 0;
	for (int i = 0; i < 10; i++) {
		sum += dp[n][i];
		sum %= 1000000000;
	}
	cout << sum;
	return 0;
}