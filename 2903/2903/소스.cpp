/*
2016.9.20
BaekJoon Online Judge
Problem Solving

Seong Joon Seo (ID: jjunCoder)

Problem
#2903
중앙 이동 알고리즘
*/

#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int n;
	cin.sync_with_stdio(false);
	cin >> n;
	printf("%lld", (long long)((pow(2, n) + 1)*(pow(2, n) + 1)));

	return 0;
}
