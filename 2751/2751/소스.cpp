/*
2016.8.22
BaekJoon Online Judge
Problem Solving

Seong Joon Seo (ID: jjunCoder)

Problem
#2751
수 정렬하기 2
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v1, v2;

int main() {
	int n, input;	
	cin.sync_with_stdio(false);
	cin >> n;
	vector<int> result(n);
	for (int i = 0; i < n/2; i++) {
		cin >> input;
		v1.push_back(input);
	}
	for (int i = 0; i < n - n / 2; i++) {
		cin >> input;
		v2.push_back(input);
	}
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	merge(v1.begin(), v1.end(), v2.begin(), v2.end(), result.begin());
	for (int i = 0; i < n; i++) {
		printf("%d\n", result[i]);
	}
	return 0;
}