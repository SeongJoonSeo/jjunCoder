/*
2016.9.22
BaekJoon Online Judge
Problem Solving

Seong Joon Seo (ID: jjunCoder)

Problem
#1225
이상한 곱셈
*/

#include <iostream>
#include <string>

using namespace std;

int main() {
	string a, b;
	cin.sync_with_stdio(false);
	cin >> a >> b;
	long long x, y, sum = 0;

	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < b.size(); j++) {
			x = a[i] - 48;
			y = b[j] - 48;
			sum += x*y;
		}
	}
	cout << sum;
	return 0;
}