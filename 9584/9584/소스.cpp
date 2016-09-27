/*
2016.9.27
BaekJoon Online Judge
Problem Solving

Seong Joon Seo (ID: jjunCoder)

Problem
#9584
Fraud Busters
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	string str, input;
	int n;
	vector<string> v;
	cin.sync_with_stdio(false);
	cin >> str >> n;
	for (int i = 0; i < n; i++) {
		bool correct = true;
		cin >> input;
		for (int j = 0; j < input.size(); j++) {
			if (str[j] == input[j] || str[j] == '*')
				continue;
			correct = false;
		}
		if (correct)
			v.push_back(input);
	}
	printf("%d\n", v.size());
	for (int i = 0; i < v.size(); i++)
		printf("%s\n", v[i].c_str());
	return 0;
}