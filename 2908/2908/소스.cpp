/*
2016.9.20
BaekJoon Online Judge
Problem Solving

Seong Joon Seo (ID: jjunCoder)

Problem
#2908
상수
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	string a, b;
	cin.sync_with_stdio(false);
	cin >> a >> b;
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	int A, B;
	A = atoi(a.c_str());
	B = atoi(b.c_str());
	if (A > B)
		cout << A;
	else
		cout << B;
	return 0;
}