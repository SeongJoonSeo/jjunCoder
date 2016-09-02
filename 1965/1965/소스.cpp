/*
2016.9.2
BaekJoon Online Judge
Problem Solving

Seong Joon Seo (ID: jjunCoder)

Problem
#1965
상자넣기
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> seq, dp;

int solve(int start) {
	if (start == seq.size()) return 0;
	int& ret = dp[start];
	if (ret != -1) return ret;
	ret = 1;
	for (int next = start + 1; next < seq.size(); next++) {
		if (seq[next] > seq[start])
			ret = max(ret, 1 + solve(next));
	}
	return ret;
}

int main() {
	int n, cost;
	cin.sync_with_stdio(false);
	cin >> n;
	dp.assign(n, -1);
	for (int i = 0; i < n; i++) {
		cin >> cost;
		seq.push_back(cost);
	}
	int maxi = -1;
	for (int i = 0; i < n; i++) {
		maxi = max(maxi,solve(i));
	}
	cout << maxi;
	return 0;
}