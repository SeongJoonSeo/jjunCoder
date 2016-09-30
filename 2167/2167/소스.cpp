/*
2016.9.29
BaekJoon Online Judge
Problem Solving

Seong Joon Seo (ID: jjunCoder)

Problem
#2167
2차원 배열의 합
*/

#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, m, k;
	long long input;
	cin.sync_with_stdio(false);
	cin >> n >> m;
	vector<vector<long long>> v, dp;
	v.assign(n, vector<long long>(m, 0));
	dp.assign(n, vector<long long>(m, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> input;
			v[i][j] = input;
		}
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (j == 0)
				dp[i][j] = v[i][j];
			else
				dp[i][j] = v[i][j] + dp[i][j - 1];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (i != 0)
				dp[i][j] += dp[i - 1][j];

	cin >> k;
	int a, b, x, y;
	long long ret;
	for (int i = 0; i < k; i++) {
		cin >> a >> b >> x >> y;
		a--; b--; x--; y--;
		if (a == 0 && b == 0)
			ret = dp[x][y];
		else if (a == 0 && b != 0)
			ret = (dp[x][y] - dp[x][b - 1]);
		else if (a != 0 && b == 0)
			ret = (dp[x][y] - dp[a - 1][y]);
		else
			ret = (dp[x][y] + dp[a - 1][b - 1] - dp[a - 1][y] - dp[x][b - 1]);
		printf("%lld\n", ret);
	}
	return 0;
}