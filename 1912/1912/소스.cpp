/*
2016.9.29
BaekJoon Online Judge
Problem Solving

Seong Joon Seo (ID: jjunCoder)

Problem
#1912
연속합
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int INF = 987654321;

int main() {
	int n, input;
	cin.sync_with_stdio(false);
	cin >> n;
	vector<vector<int>> dp;
	vector<int> v;

	dp.assign(n, vector<int>(n, INF));
	for (int i = 0; i < n; i++) {
		cin >> input;
		v.push_back(input);
	}
	return 0;
}