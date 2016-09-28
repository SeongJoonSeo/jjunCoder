/*
2016.9.28
BaekJoon Online Judge
Problem Solving

Seong Joon Seo (ID: jjunCoder)

Problem
#1764
듣보잡
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

int main() {
	int n, m;
	cin.sync_with_stdio(false);
	cin >> n >> m;
	string input;
	vector<string> v;
	set<string> s;
	for (int i = 0; i < n; i++) {
		cin >> input;
		s.insert(input);
	}
	for (int i = 0; i < m; i++) {
		cin >> input;
		if (s.find(input) != s.end())//found
			v.push_back(input);
	}
	sort(v.begin(), v.end());
	printf("%d\n", v.size());
	for (auto it = v.begin(); it != v.end(); it++)
		printf("%s\n", (*it).c_str());

	return 0;
}