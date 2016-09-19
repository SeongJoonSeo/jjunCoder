/*
2016.9.19
BaekJoon Online Judge
Problem Solving

Seong Joon Seo (ID: jjunCoder)

Problem
#1550
16진수
*/

#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	string str;
	cin.sync_with_stdio(false);
	cin >> str;
	reverse(str.begin(), str.end());
	int digit = 0;
	int ret = 0;
	for (int i = 0; i < str.size(); i++) {
		if(str[i]>=48&&str[i]<=57)
			ret += (str[i] - 48) * pow(16, digit++);
		else
			ret += (str[i] - 55) * pow(16, digit++);
	}
	cout << ret;
	return 0;
}