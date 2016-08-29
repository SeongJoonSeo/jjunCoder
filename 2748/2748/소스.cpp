/*
2016.8.26
BaekJoon Online Judge
Problem Solving

Seong Joon Seo (ID: jjunCoder)

Problem
#2748
*/

#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<long long> v(91, 0);
	int n;
	cin.sync_with_stdio(false);
	cin >> n;
	v[0] = 0;
	v[1] = 1;
	for (int i = 2; i <= 90; i++) {
		v[i] = v[i - 1] + v[i - 2];
	}
	cout << v[n];
	return 0;
}