/*
2016.9.6
BaekJoon Online Judge
Problem Solving

Seong Joon Seo (ID: jjunCoder)

Problem
#11399
ATM
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, p;
	cin.sync_with_stdio(false);
	cin >> n;
	vector<int> price;
	for (int i = 0; i < n; i++) {
		cin >> p;
		price.push_back(p);
	}
	sort(price.begin(), price.end());
	int s = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			s += price[j];
		}
	}
	cout << s;
	return 0;
}