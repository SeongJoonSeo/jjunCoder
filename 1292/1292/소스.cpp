/*
2016.9.19
BaekJoon Online Judge
Problem Solving

Seong Joon Seo (ID: jjunCoder)

Problem
#1292
쉽게 푸는 문제
*/

#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<int> v,ps;
	for (int i = 1; i <= 50; i++) {
		for (int j = 0; j < i; j++) {
			v.push_back(i);
		}
	}
	int sum = 0;
	for (int i = 0; i < v.size(); i++) {
		sum += v[i];
		ps.push_back(sum);
	}
	cin.sync_with_stdio(false);
	int a, b;
	cin >> a >> b;
	if (a == 1) {
		printf("%d", ps[b - 1]);
	}
	else {
		printf("%d", ps[b - 1] - ps[a - 2]);
	}	
	return 0;
}