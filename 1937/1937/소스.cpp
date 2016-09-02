/*
2016.9.2
BaekJoon Online Judge
Problem Solving

Seong Joon Seo (ID: jjunCoder)

Problem
#1937
욕심쟁이 판다
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int> > table, dp;
int n;

int solve(int y, int x, int cost) {
	if (x < 0 || y < 0 || x >= n || y >= n) return 0;
	if (table[y][x] <= cost) return 0;
	int& ret = dp[y][x];
	if (ret != -1) return ret;
	int temp = table[y][x];
	ret = max(ret, solve(y + 1, x, temp)+1);
	ret = max(ret, solve(y, x + 1, temp)+1);
	ret = max(ret, solve(y - 1, x, temp)+1);
	return ret = max(ret, solve(y, x - 1, temp)+1);
}

int main() {
	cin.sync_with_stdio(false);
	cin >> n;
	dp.assign(n, vector<int>(n, -1));
	table.assign(n, vector<int>(n, -1));
	int cost,maxi=-1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> cost;
			table[i][j] = cost;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			maxi = max(maxi,solve(i, j, -1));
		}
	}
	cout << maxi;
	return 0;
}