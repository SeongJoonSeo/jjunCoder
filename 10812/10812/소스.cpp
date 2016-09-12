/*
2016.9.12
BaekJoon Online Judge
Problem Solving

Seong Joon Seo (ID: jjunCoder)

Problem
#10812
바구니 순서 바꾸기
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, m, a, b, c, temp;
	cin.sync_with_stdio(false);
	cin >> n >> m;
	vector<int> bucket;
	for (int i = 0; i < n + 1; i++)
		bucket.push_back(i);
	for (int i = 0; i < m; i++) {
		vector<int> temp;
		cin >> a >> b >> c;
		auto start = bucket.begin();
		auto j = bucket.begin() + a;
		for (auto it = start + a; it != start + c; it++)
			temp.push_back(*it);
		for (auto it = start + c; it != start + b + 1; it++) {
			*j = *it; j++;
		}
		for (auto k = temp.begin(); k != temp.end(); k++) {
			*j = *k; j++;
		}			
	}
	for (auto it = bucket.begin()+1; it != bucket.end(); it++)
		printf("%d ", *it);
	return 0;
}