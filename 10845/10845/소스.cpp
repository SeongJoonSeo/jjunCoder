/*
2016.8.25
BaekJoon Online Judge
Problem Solving

Seong Joon Seo (ID: jjunCoder)

Problem
#10845
ť
*/

#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main() {
	int n, x;
	string str;
	queue<int> myQ;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> str;
		if (str == "push") {
			cin >> x;
			myQ.push(x);
		}
		else if (str == "pop") {
			if (myQ.empty())
				printf("%d\n", -1);
			else
			{
				printf("%d\n", myQ.front());
				myQ.pop();
			}
		}
		else if (str == "size") {
			printf("%d\n", myQ.size());
		}
		else if (str == "empty") {
			if (myQ.empty())
				printf("%d\n", 1);
			else
				printf("%d\n", 0);
		}
		else if (str == "front") {
			if (myQ.empty())
				printf("%d\n", -1);
			else
			{
				printf("%d\n", myQ.front());
			}
		}
		else if (str == "back") {
			if (myQ.empty())
				printf("%d\n", -1);
			else
			{
				printf("%d\n", myQ.back());
			}
		}
	}
	return 0;
}