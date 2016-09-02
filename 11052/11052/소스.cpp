/*
2016.9.2
BaekJoon Online Judge
Problem Solving

Seong Joon Seo (ID: jjunCoder)

Problem
#11052
붕어빵 판매하기
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> dp, costs;
int num;

int solve(int n) {
	if (n <= 0)
		return 0;
	int& ret = dp[n];
	if (ret != -1) return ret;
	for (int i = 1; i <= n; i++)
		ret = max(ret, solve(n - i) + costs[i]);
	return ret;
}

int main() {
	int cost;
	cin.sync_with_stdio(false);
	cin >> num;
	dp.assign(num + 1, -1);
	costs.push_back(0);
	for (int i = 0; i < num; i++) {
		cin >> cost;
		costs.push_back(cost);
	}
	cout << solve(num);
	return 0;
}