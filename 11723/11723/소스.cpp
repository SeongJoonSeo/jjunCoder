/*
2016.9.12
BaekJoon Online Judge
Problem Solving

Seong Joon Seo (ID: jjunCoder)

Problem
#11723
집합
*/

#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {
	int m, x;
	string input;
	cin.sync_with_stdio(false);
	cin >> m;
	set<int> s;
	set<int> s1, s2;
	for (int i = 1; i < 21; i++) {
		s1.insert(i);
	}
	for (int i = 0; i < m; i++) {
		cin >> input;
		if (input == "add") {
			cin >> x;
			s.insert(x);
		}
		else if(input=="remove") {
			cin >> x;
			if (s.find(x) != s.end()) {
				s.erase(x);
			}
		}
		else if (input == "check") {
			cin >> x;
			s.find(x) != s.end() ? printf("%d\n", 1) : printf("%d\n", 0);
		}
		else if (input == "toggle") {
			cin >> x;
			if (s.find(x) != s.end())
				s.erase(x);
			else
				s.insert(x);
		}
		else if (input == "all") {
			s = s1;
		}
		else if (input == "empty") {
			s = s2;
		}
	}
	return 0;
}