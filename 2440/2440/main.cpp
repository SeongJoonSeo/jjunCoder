/*
2016.8.22
BaekJoon Online Judge
Problem Solving

Seong Joon Seo (ID: jjunCoder)

Problem
#2440
º°Âï±â - 3
*/

#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = n-i; j > 0; j--) {
			printf("*");
		}
		printf("\n");
	}
	return 0;
}