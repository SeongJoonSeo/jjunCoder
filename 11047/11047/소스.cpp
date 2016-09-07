/*
2016.9.7
BaekJoon Online Judge
Problem Solving

Seong Joon Seo (ID: jjunCoder)

Problem
#11047
동전 0
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, k, coin, ret = 0;
	cin.sync_with_stdio(false);
	cin >> n >> k;
	vector<int> coins;
	for (int i = 0; i < n; i++) {
		cin >> coin;
		coins.push_back(coin);
	}
	for (auto it = coins.rbegin(); it != coins.rend(); it++) {
		if (k >= *it) {
			int temp = k / (*it);
			ret += temp;
			k -= temp*(*it);
		}
	}
	cout << ret;
	return 0;
}