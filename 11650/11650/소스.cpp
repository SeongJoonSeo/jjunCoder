/*
2016.9.13
BaekJoon Online Judge
Problem Solving

Seong Joon Seo (ID: jjunCoder)

Problem
#11650
좌표 정렬하기
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, x, y;
	cin.sync_with_stdio(false);
	cin >> n;
	vector<pair<int, int> > v;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		v.push_back(make_pair(x, y));
	}
	sort(v.begin(), v.end());
	for (auto it = v.begin(); it != v.end(); it++) {
		printf("%d ", (*it).first);
		printf("%d\n", (*it).second);
	}
	return 0;
}