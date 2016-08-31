/*
2016.8.26
BaekJoon Online Judge
Problem Solving

Seong Joon Seo (ID: jjunCoder)

Problem
#2747
*/

#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<long long> v(46,0);
	int n;
	cin.sync_with_stdio(false);
	cin >> n;
	v[0] = 0;
	v[1] = 1;
	for (int i = 2; i <= 45; i++) {
		v[i] = v[i - 1] + v[i - 2];
	}
	cout << v[n];
	return 0;
}