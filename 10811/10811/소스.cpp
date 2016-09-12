/*
2016.9.12
BaekJoon Online Judge
Problem Solving

Seong Joon Seo (ID: jjunCoder)

Problem
#10811
바구니 뒤집기
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, m, a, b;
	cin.sync_with_stdio(false);
	cin >> n >> m;
	vector<int> bucket;
	for (int i = 0; i < n+1; i++)
		bucket.push_back(i);	
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		reverse(bucket.begin() + a, bucket.begin() + b + 1);
	}
	for (auto it = bucket.begin() + 1; it != bucket.end(); it++)
		printf("%d ", *it);
	return 0;
}