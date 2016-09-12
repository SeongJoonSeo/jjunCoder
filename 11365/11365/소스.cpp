/*
2016.9.12
BaekJoon Online Judge
Problem Solving

Seong Joon Seo (ID: jjunCoder)

Problem
#11365
!밀비 급일
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	string input;
	cin.sync_with_stdio(false);
	getline(cin, input);
	while (input != "END") {
		reverse(input.begin(), input.end());
		cout << input << endl;
		getline(cin, input);
	}
	return 0;
}