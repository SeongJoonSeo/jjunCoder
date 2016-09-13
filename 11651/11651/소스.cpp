/*
2016.9.13
BaekJoon Online Judge
Problem Solving

Seong Joon Seo (ID: jjunCoder)

Problem
#11651
좌표 정렬하기 2
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin.sync_with_stdio(false);
	cin >> n;
	int x, y;
	vector<pair<int, int> > v;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		v.push_back(make_pair(y, x));
	}
	sort(v.begin(), v.end());
	for (auto it = v.begin(); it != v.end(); it++) {
		printf("%d ", (*it).second);
		printf("%d\n", (*it).first);
	}
	return 0;
}