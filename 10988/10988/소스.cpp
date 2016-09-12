/*
2016.9.12
BaekJoon Online Judge
Problem Solving

Seong Joon Seo (ID: jjunCoder)

Problem
#10988
팰린드롬인지 확인하기
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	string input;
	cin.sync_with_stdio(false);
	cin >> input;
	int mid = input.size() / 2;
	int left = mid - 1;
	int right = mid;
	if (input.size() % 2 != 0)
		right++;
	bool isPal = true;
	while (right != input.size()) {
		if (input[left] != input[right]) {
			isPal = false;
			break;
		}
		left--;
		right++;
	}
	if (isPal)
		cout << 1;
	else
		cout << 0;
	return 0;
}