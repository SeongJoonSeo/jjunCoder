/*
2016.8.22
BaekJoon Online Judge
Problem Solving

Seong Joon Seo (ID: jjunCoder)

Problem
#2675
문자열 반복
*/

#include <iostream>
#include <string>
using namespace std;

int main() {
	int t,r;
	cin >> t;
	string s;
	for (int i = 0; i < t; i++) {
		cin >> r >> s;
		for (int j = 0; j < s.size(); j++) {
			for (int k = 0; k < r; k++) {
				printf("%c", s[j]);
			}
		}
		printf("\n");
	}
	return 0;
}