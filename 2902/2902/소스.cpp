/*
2016.9.20
BaekJoon Online Judge
Problem Solving

Seong Joon Seo (ID: jjunCoder)

Problem
#2902
KMP는 왜 KMP일까?
*/

#include <iostream>
#include <string>
using namespace std;

int main() {
	string input;
	cin.sync_with_stdio(false);
	cin >> input;
	cout << input[0];
	for (int i = 1; i < input.size(); i++)
		if (input[i] == '-')
			cout << input[i + 1];
	
	return 0;
}