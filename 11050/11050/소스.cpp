/*
2016.8.26
BaekJoon Online Judge
Problem Solving

Seong Joon Seo (ID: jjunCoder)

Problem
#11050
이항 계수 1
*/

#include <iostream>

using namespace std;

int main() {
	int n, k;
	cin.sync_with_stdio(false);
	cin >> n >> k;
	int result = 1, div = 1, div2 = 1;
	for (int i = 1; i <= n; i++) {
		result *= i;
	}
	for (int i = 1; i <= k; i++) {
		div *= i;
	}
	for (int i = 1; i <= n-k; i++) {
		div2 *= i;
	}
	cout << result / (div*div2);
	return 0;
}