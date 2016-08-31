/*
2016.8.31
BaekJoon Online Judge
Problem Solving

Seong Joon Seo (ID: jjunCoder)

Problem
#11053
가장 긴 증가하는 부분 수열
(LIS: Longeset Increasing Subsequence)
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> dp, seq;

int LIS(int start) {
	int& ret = dp[start];
	if (ret != -1) return ret;
	ret = 1;
	for (int next = start + 1; next < seq.size(); next++)
		if (seq[next] > seq[start])
			ret = max(ret, 1 + LIS(next));
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
	int maxLength = 0;
	for (int i = 0; i < n; i++)
		maxLength = max(maxLength, LIS(i));
	cout << maxLength;
	return 0;
}