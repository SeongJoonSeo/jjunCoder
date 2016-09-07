/*
2016.9.7
BaekJoon Online Judge
Problem Solving

Seong Joon Seo (ID: jjunCoder)

Problem
#1946
신입 사원
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int t;
	cin.sync_with_stdio(false);
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n, a, b, ret = 1;
		cin >> n;
		vector<pair<int, int> > v;
		for (int j = 0; j < n; j++) {
			cin >> a >> b;
			v.push_back(make_pair(a, b));
		}
		sort(v.begin(), v.end());
		pair<int, int> winner = v.front();
		for (int j = 0; j < n; j++) {
			if (v[j].second < winner.second) {
				winner = v[j];
				ret++;
			}
		}
		printf("%d\n", ret);

	}
	return 0;
}