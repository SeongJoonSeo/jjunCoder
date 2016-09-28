/*
2016.9.28
BaekJoon Online Judge
Problem Solving

Seong Joon Seo (ID: jjunCoder)

Problem
#1181
단어 정렬
*/

#include <iostream>
#include <set>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main() {
	int n;
	string input;
	cin.sync_with_stdio(false);
	cin >> n;
	
	vector<set<string> > vec;
	vec.assign(51,set<string>());
	
	for (int i = 0; i < n; i++) {
		cin >> input;
		vec[input.size()].insert(input);
	}
	for (int i = 1; i < vec.size(); i++)
		if (!vec[i].empty()) 
			for (auto it = vec[i].begin(); it != vec[i].end(); it++) 
				printf("%s\n", (*it).c_str());
	return 0;
}