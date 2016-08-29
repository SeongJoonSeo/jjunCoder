/*
2016.8.25
BaekJoon Online Judge
Problem Solving

Seong Joon Seo (ID: jjunCoder)

Problem
#10866
덱
*/

#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main() {
	deque<int> d;
	string cmd;
	int n, x;
	cin.sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> cmd;
		if (cmd == "push_front") {
			cin >> x;
			d.push_front(x);
		}
		else if (cmd == "push_back") {
			cin >> x;
			d.push_back(x);
		}
		else if (cmd == "pop_front") {
			if (d.empty())
				printf("%d\n", -1);
			else {
				printf("%d\n", d.front());
				d.pop_front();
			}
		}
		else if (cmd == "pop_back") {
			if (d.empty())
				printf("%d\n", -1);
			else {
				printf("%d\n", d.back());
				d.pop_back();
			}
		}
		else if (cmd == "size") {
			printf("%d\n", d.size());
		}
		else if (cmd == "empty") {
			if (d.empty())
				printf("%d\n", 1);
			else
				printf("%d\n", 0);
		}
		else if (cmd == "front") {
			if (d.empty())
				printf("%d\n", -1);
			else {
				printf("%d\n", d.front());
			}
		}
		else if (cmd == "back") {
			if (d.empty())
				printf("%d\n", -1);
			else {
				printf("%d\n", d.back());
			}
		}
	}
	return 0;
}