/*
2016.9.9
BaekJoon Online Judge
Problem Solving

Seong Joon Seo (ID: jjunCoder)

Problem
#2816
디지털 티비
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	int n;
	cin.sync_with_stdio(false);
	cin >> n;
	vector<string> ch;
	for (int i = 0; i < n; i++) {
		string input;
		cin >> input;
		ch.push_back(input);		
	}

	return 0;
}