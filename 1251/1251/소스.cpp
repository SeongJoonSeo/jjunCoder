/*
2016.9.19
BaekJoon Online Judge
Problem Solving

Seong Joon Seo (ID: jjunCoder)

Problem
#1251
단어 나누기
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	string input;
	cin.sync_with_stdio(false);
	cin >> input;
	vector<string> v;
	for (int i = 0; i < input.size() - 2; i++) {
		for (int j = i + 1; j < input.size() - 1; j++) {
			string temp = input;
			reverse(temp.begin(), temp.begin() + i + 1);
			reverse(temp.begin() + i + 1, temp.begin() + j + 1);
			reverse(temp.begin() + j + 1, temp.end());
			v.push_back(temp);
		}
	}
	sort(v.begin(), v.end());
	cout << v.front();
	return 0;
}