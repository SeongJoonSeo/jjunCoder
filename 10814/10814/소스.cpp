/*
2016.9.13
BaekJoon Online Judge
Problem Solving

Seong Joon Seo (ID: jjunCoder)

Problem
#10814
나이순 정렬
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	int n;
	cin.sync_with_stdio(false);
	cin >> n;
	vector<pair<int, pair<int, string> > > v;
	for (int i = 0; i < n; i++) {
		int age;
		string name;
		cin >> age >> name;
		v.push_back(make_pair(age, make_pair(i, name)));
	}
	sort(v.begin(), v.end());
	for (auto it = v.begin(); it != v.end(); it++) {
		printf("%d ", (*it).first);
		printf("%s\n", (*it).second.second.c_str());
	}
		
	return 0;
}