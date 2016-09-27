/*
2016.9.27
BaekJoon Online Judge
Problem Solving

Seong Joon Seo (ID: jjunCoder)

Problem
#4299
AFC 윔블던
*/

#include <iostream>

using namespace std;

int main() {
	int a, b;
	int sum, sub;
	cin.sync_with_stdio(false);
	cin >> sum >> sub;
	if ((sum + sub) % 2 != 0)
		cout << -1;
	else if (sum < sub)
		cout << -1;
	else {
		a = (sum + sub) / 2;
		b = sum - a;
		printf("%d %d", a, b);
	}

	return 0;
}