/*
2016.8.22
BaekJoon Online Judge
Problem Solving

Seong Joon Seo (ID: jjunCoder)

Problem
#10871
X보다 작은 수
*/

#include <iostream>

using namespace std;

int main() {
	int n, x, input;
	cin >> n >> x;
	for (int i = 0; i < n; i++) {
		cin >> input;
		if (input < x)
			printf("%d ", input);
	}
	return 0;
}