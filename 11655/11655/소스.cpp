/*
2016.9.12
BaekJoon Online Judge
Problem Solving

Seong Joon Seo (ID: jjunCoder)

Problem
#11655
ROT13
*/

#include <iostream>
#include <string>
using namespace std;

int main() {
	string input;
	cin.sync_with_stdio(false);
	getline(cin, input);
	for (int i = 0; i < input.size(); i++) {
		if (input[i] >= 65 && input[i] <= 90) {
			if (input[i]+13 > 90)
				input[i] -= 13;
			else
				input[i] += 13;
		}
		else if (input[i] >= 97 && input[i] <= 122) {
			if (input[i]+13 > 122)
				input[i] -= 13;
			else
				input[i] += 13;
		}
	}
	cout << input;
	return 0;
}