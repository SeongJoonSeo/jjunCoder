/*
2016.9.21
BaekJoon Online Judge
Problem Solving

Seong Joon Seo (ID: jjunCoder)

Problem
#1476
날짜 계산
*/

#include <iostream>

using namespace std;

int main() {
	int e, s, m;
	cin.sync_with_stdio(false);
	cin >> e >> s >> m;
	int year = 1;
	int a, b, c;
	a = b = c = 1;
	while (!(a == e && b == s && c == m)) {
		a++; b++; c++;		
		if (a == 16)
			a = 1;
		if (b == 29)
			b = 1;
		if (c == 20)
			c = 1;
		year++;		
	}
	cout << year;
	return 0;
}