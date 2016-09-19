/*
2016.9.19
BaekJoon Online Judge
Problem Solving

Seong Joon Seo (ID: jjunCoder)

Problem
#1964
오각형, 오각형, 오각형...
*/

#include <iostream>

using namespace std;

int main() {
	int n;
	cin.sync_with_stdio(false);
	cin >> n;
	int ret = 5;
	for (int i = 2; i <= n; i++) {
		ret += i * 2 + i + 1;
		ret %= 45678;
	}
	cout << ret;
	return 0;
}