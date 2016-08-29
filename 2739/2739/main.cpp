/*
2016.8.22
BaekJoon Online Judge
Problem Solving

Seong Joon Seo (ID: jjunCoder)

Problem
#2739
±¸±¸´Ü
*/

#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	for (int i = 1; i < 10; i++) {
		cout << n << " * " << i << " = " << n*i << endl;
	}
	return 0;
}