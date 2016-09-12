/*
2016.9.12
BaekJoon Online Judge
Problem Solving

Seong Joon Seo (ID: jjunCoder)

Problem
#10987
모음의 개수
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	string input;
	cin.sync_with_stdio(false);
	cin >> input;
	int ret = 0;
	for (int i = 0; i < input.size(); i++)
		if (input[i] == 97 || input[i] == 101 || input[i] == 105 || input[i] == 111 || input[i] == 117)
			ret++;
	cout << ret;
	return 0;
}