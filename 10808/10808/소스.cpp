/*
2016.9.12
BaekJoon Online Judge
Problem Solving

Seong Joon Seo (ID: jjunCoder)

Problem
#10808
알파벳 개수
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	vector<int> v(26, 0);
	cin.sync_with_stdio(false);
	string input;
	cin >> input;
	for (int i = 0; i < input.size(); i++) {
		v[input[i] - 97]++;
	}
	for (int i = 0; i < v.size(); i++) {
		printf("%d ", v[i]);
	}
	return 0;
}