/*
2016.8.22
BaekJoon Online Judge
Problem Solving

Seong Joon Seo (ID: jjunCoder)

Problem
#8393
гу
*/

#include <iostream>

using namespace std;

int main() {
	int n,sum=0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		sum += i;
	}
	cout << sum;
	return 0;
}