/*
2016.8.22
BaekJoon Online Judge
Problem Solving

Seong Joon Seo (ID: jjunCoder)

Problem
#2441
º°Âï±â - 4
*/

#include <iostream>

using namespace std;

int main() {
	int n,count=0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (j >= count)
				printf("*");
			else
				printf(" ");
		}
		printf("\n");
		count++;
	}
	return 0;
}