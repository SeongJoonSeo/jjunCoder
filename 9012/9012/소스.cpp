/*
2016.9.29
BaekJoon Online Judge
Problem Solving

Seong Joon Seo (ID: jjunCoder)

Problem
#9012
괄호
*/

#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool isVPS(string input) {
	stack<char> s;
	auto it = input.begin();
	s.push(*(it++));
	while (it != input.end()) {
		if (*it == '(') {
			s.push(*(it++));
		}
		else {
			if (s.empty())
				return false;
			if (s.top() != '(')
				return false;
			else
				s.pop(); it++;
		}
	}
	if (!s.empty())
		return false;
	else
		return true;
}

int main() {
	int t;
	cin.sync_with_stdio(false);
	cin >> t;
	while (t--) {
		string input;
		cin >> input;
		if (isVPS(input))
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}