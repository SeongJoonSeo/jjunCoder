/*
2016.8.22
BaekJoon Online Judge
Problem Solving

Seong Joon Seo (ID: jjunCoder)

Problem
#10828
스택
*/

#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
	int n, x;
	cin >> n;
	string cmd;
	stack<int> s;
	for (int i = 0; i < n; i++) {
		cin >> cmd;
		if (cmd == "push") {
			cin >> x;
			s.push(x);
		}
		else if (cmd == "pop") {
			if (s.empty())
				printf("%d\n", -1);
			else {
				printf("%d\n", s.top());
				s.pop();
			}
		}
		else if (cmd == "size") {
			printf("%d\n", s.size());
		}
		else if (cmd == "empty") {
			if (s.empty())
				printf("%d\n", 1);
			else
				printf("%d\n", 0);
		}
		else if (cmd == "top") {
			if (s.empty())
				printf("%d\n", -1);
			else
				printf("%d\n", s.top());
		}
	}
	return 0;
}