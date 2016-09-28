/*
2016.9.28
BaekJoon Online Judge
Problem Solving

Seong Joon Seo (ID: jjunCoder)

Problem
#9557
Arabic and English
*/

#include <iostream>
#include <string>

using namespace std;

int main() {
	int t;
	cin.sync_with_stdio(false);
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		string input, appending;
		bool arabic = false;
		bool alpha = false;
		bool canSwap = false;
		for (int i = 0; i < n; i++) {			
			cin >> input;
			if (input.front() == '#')
				arabic = true;
		}
	}
	return 0;
}