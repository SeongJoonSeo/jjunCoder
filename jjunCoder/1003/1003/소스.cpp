/*
2016.8.29
BaekJoon Online Judge
Problem Solving

Seong Joon Seo (ID: jjunCoder)

Problem
#1003
피보나치 함수
*/

#include <iostream>
#include <vector>

using namespace std;

vector<pair<int,int> > dp;

pair<int,int> sol(int n) {
	if (n == 0)
		return make_pair(1, 0);
	if (n == 1)
		return make_pair(0, 1);
	pair<int, int>& ret = dp[n];
	if (ret.first != -1)
		return ret;
	ret.first = sol(n - 1).first + sol(n - 2).first;
	ret.second = sol(n - 1).second + sol(n - 2).second;
	return ret;
}

int main() {
	int t, n;
	cin.sync_with_stdio(false);
	cin >> t;
	dp.assign(41, make_pair(-1, -1));
	dp[0] = make_pair(1, 0);
	dp[1] = make_pair(0, 1);
	sol(40);
	for (int i = 0; i < t; i++) {
		cin >> n;
		printf("%d ", dp[n].first);
		printf("%d\n", dp[n].second);
	}

	return 0;
}