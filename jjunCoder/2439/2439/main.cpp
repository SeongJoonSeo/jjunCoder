/*
2016.8.22
BaekJoon Online Judge
Problem Solving

Seong Joon Seo (ID: jjunCoder)

Problem
#2439
º°Âï±â - 2
*/

#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	int count = 1;
	for (int i = 0; i < n; i++) {		
		for (int j = n; j > 0; j--) {
			if (j <= count)
				printf("*");			
			else
				printf(" ");
		}
		count++;
		printf("\n");
	}
	return 0;
}