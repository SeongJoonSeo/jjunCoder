/*
2016.8.22
BaekJoon Online Judge
Problem Solving

Seong Joon Seo (ID: jjunCoder)

Problem
#1152
단어의 개수
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	string str;
	vector<string> v;
	while (cin >> str) {
		v.push_back(str);
	}
	cout << v.size();
	return 0;
}