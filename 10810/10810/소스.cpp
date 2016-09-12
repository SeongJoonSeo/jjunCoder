/*
2016.9.12
BaekJoon Online Judge
Problem Solving

Seong Joon Seo (ID: jjunCoder)

Problem
#10810
공 넣기
*/

#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int main() {
	int n, m, i, j, k;
	cin.sync_with_stdio(false);
	cin >> n >> m;
	vector<int> bucket(n+1,0);
	for (int a = 0; a < m; a++) {
		cin >> i >> j >> k;
		for (int b = i; b <= j; b++) {
			bucket[b] = k;
		}
	}
	for (auto it = bucket.begin()+1; it != bucket.end(); it++)
		printf("%d ", *it);
	return 0;
}