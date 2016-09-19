/*
2016.9.19
BaekJoon Online Judge
Problem Solving

Seong Joon Seo (ID: jjunCoder)

Problem
#2526
싸이클
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, p;
	vector<int> s;
	cin.sync_with_stdio(false);
	cin >> n >> p;
	s.push_back(n);
	int temp = (n*n) % p;
	if (temp == n) {
		cout << 1; return 0;
	}
	while (s.find(temp) == s.end()) {
		s.insert(temp);
		temp = (temp*n) % p;
		count++;
	}
	cout << count;
	return 0;
}