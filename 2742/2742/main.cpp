/*
2016.8.22
BaekJoon Online Judge
Problem Solving

Seong Joon Seo (ID: jjunCoder)

Problem
#2742
기찍 N
*/

#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	for (int i = n; i > 0; i--) {
		//cout 으로 했더니 시간초과남..
		printf("%d\n", i);
	}
	return 0;
}