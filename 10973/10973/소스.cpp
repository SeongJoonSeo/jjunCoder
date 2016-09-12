/*
2016.9.12
BaekJoon Online Judge
Problem Solving

Seong Joon Seo (ID: jjunCoder)

Problem
#10973
이전 순열
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, input;
	cin.sync_with_stdio(false);
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> input;
		v[i] = input;
	}
	if (prev_permutation(v.begin(), v.end()))
		for (auto it = v.begin(); it != v.end(); it++)
			printf("%d ", *it);
	else
		printf("%d", -1);
	return 0;
}