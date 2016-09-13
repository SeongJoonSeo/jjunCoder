/*
2016.9.13
BaekJoon Online Judge
Problem Solving

Seong Joon Seo (ID: jjunCoder)

Problem
#10819
차이를 최대로
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int n;
vector<int> input;
vector<int> v;

int solve(vector<bool> visit,int idx) {
	visit[idx] = true;
	if (v.size() == n) {
		int ret = 0;
		for (int i = 0; i+1 < n; i++) {
			ret += abs(v[i] - v[i + 1]);
		}
		return ret;
	}
	int maxi = -1;
	for (int i = 0; i < n; i++) {
		if (!visit[i]) {
			v.push_back(input[i]);
			maxi = max(maxi, solve(visit, i));
			v.pop_back();
		}
	}
	return maxi;
}

int main() {
	int a;
	cin.sync_with_stdio(false);
	cin >> n;
	vector<bool> visit(n,false);
	for (int i = 0; i < n; i++) {
		cin >> a;
		input.push_back(a);
	}
	int maxi = -1;
	for (int i = 0; i < n; i++) {
		v.push_back(input[i]);
		maxi = max(maxi, solve(visit, i));
		v.pop_back();
	}
	cout << maxi;
	return 0;
}