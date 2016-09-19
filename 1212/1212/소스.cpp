/*
2016.9.19
BaekJoon Online Judge
Problem Solving

Seong Joon Seo (ID: jjunCoder)

Problem
#1212
8진수 2진수
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	char c;
	cin.sync_with_stdio(false);
	cin >> c;
	if (c == 48) {
		printf("%d", 0);
		return 0;
	}
	else {
		bool first = true;
		while (!cin.eof()) {
			int n = c - 48;
			switch (n) {
			case 0:
				printf("000");
				break;
			case 1:
				if (first) {
					printf("1");
					first = false;
				}
				else
					printf("001");
				break;
			case 2:
				if (first) {
					printf("10");
					first = false;
				}
				else
					printf("010");
				break;
			case 3:
				if (first) {
					printf("11");
					first = false;
				}
				else
					printf("011");
				break;
			case 4:
				if (first) {
					printf("100");
					first = false;
				}
				else
					printf("100");
				break;
			case 5:
				if (first) {
					printf("101");
					first = false;
				}
				else
					printf("101");
				break;
			case 6:
				if (first) {
					printf("110");
					first = false;
				}
				else
					printf("110");
				break;
			case 7:
				if (first) {
					printf("111");
					first = false;
				}
				else
					printf("111");
				break;
			}
			cin >> c;
		}
	}
	return 0;
}