/*
2016.8.22
BaekJoon Online Judge
Problem Solving

Seong Joon Seo (ID: jjunCoder)

Problem
#1978
소수 찾기
*/

#include <iostream>

using namespace std;

bool isPrime(int n) {
	if (n == 1)
		return false;
	for (int i = 2; i < n; i++)
		if (n%i == 0)
			return false;
	return true;
}

int main() {
	int n, input, count = 0;
	cin.sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> input;
		if (isPrime(input))
			count++;
	}
	cout << count;
	return 0;
}