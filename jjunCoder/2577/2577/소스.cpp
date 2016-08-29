/*
2016.8.22
BaekJoon Online Judge
Problem Solving

Seong Joon Seo (ID: jjunCoder)

Problem
#2577
숫자의 개수
*/

#include <iostream>
#include <string>

using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	long result = a*b*c;
	string str = to_string(result);
	int numbers[10] = { 0, };
	for (int i = 0; i < str.size(); i++) {
		numbers[(str[i] - 48)]++;
	}
	for (int i = 0; i < 10; i++) {
		cout << numbers[i] << endl;
	}
	return 0;
}