/*
2016.9.2
BaekJoon Online Judge
Problem Solving

Seong Joon Seo (ID: jjunCoder)

Problem
#10164
격자상의 경로
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, m, k, x, y;
	cin.sync_with_stdio(false);
	cin >> n >> m >> k;
	//이항계수를 dp에 구해놓는다.
	vector<vector<long long> > dp;
	dp.assign(32, vector<long long>(32, -1));
	for (int i = 1; i < 31; i++) {
		for (int j = 0; j < 31; j++) {
			if (j == 0 || j == i)
				dp[i][j] = 1;
			if (j != 0)
				dp[i + 1][j] = (dp[i][j - 1] + dp[i][j]);
		}
	}
	//길찾기를 시작한다.
	if (k == 0) {
		x = m - 1;
		y = n - 1;
		cout << dp[y + x][y];
	}
	else if (k%m == 0) {
		x = m - 1;
		y = k / m - 1;
		cout << dp[y + x][y];
	}
	else {
		x = k%m - 1;
		y = k / m;
		cout << dp[y + x][y] * dp[n - 1 - y + m - 1 - x][m - 1 - x];
	}
	return 0;
}