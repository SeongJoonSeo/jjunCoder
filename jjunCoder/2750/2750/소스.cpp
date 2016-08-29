/*
2016.8.22
BaekJoon Online Judge
Problem Solving

Seong Joon Seo (ID: jjunCoder)

Problem
#2750
수 정렬하기
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, input;
	vector<int> v;
	cin.sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> input;
		v.push_back(input);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++) {
		printf("%d\n", v[i]);
	}
	return 0;
}