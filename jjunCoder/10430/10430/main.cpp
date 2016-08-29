/*
2016.8.22
BaekJoon Online Judge
Problem Solving

Seong Joon Seo (ID: jjunCoder)

Problem
#10430
³ª¸ÓÁö
*/

#include <iostream>

using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	cout << (a + b) % c << endl;
	cout << (a%c + b%c) % c << endl;
	cout << (a*b) % c << endl;
	cout << (a%c*b%c) % c << endl;
	return 0;
}
