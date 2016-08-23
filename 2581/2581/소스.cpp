/*
2016.8.22
BaekJoon Online Judge
Problem Solving

Seong Joon Seo (ID: jjunCoder)

Problem
#2581
¼Ò¼ö
*/

#include <iostream>
#include <vector>
#include <algorithm>

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
	int m, n, sum = 0, mini=1000000;
	cin >> m >> n;
	vector<int> primes;
	for (int i = m; i <= n; i++) {
		if (isPrime(i))
			primes.push_back(i);
	}
	if (primes.empty())
		cout << -1;
	else {
		for (int i = 0; i < primes.size(); i++) {
			sum += primes[i];
			mini = min(mini, primes[i]);
		}
		cout << sum << endl << mini;
	}
	return 0;
}