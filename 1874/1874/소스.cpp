/*
2016.8.22
BaekJoon Online Judge
Problem Solving

Seong Joon Seo (ID: jjunCoder)

Problem
#1874
스택 수열
*/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
	int n, input, item = 1;
	vector<char> v;
	stack<int> s;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> input;
		while(item<=input) {
			v.push_back('+');
			s.push(item++);
		}
		if (input < item) {
			if (s.top() != input) {
				cout << "NO";
				return 0;
			}
			v.push_back('-');
			s.pop();
		}
	}
	for (int i = 0; i < v.size(); i++) {
		printf("%c\n", v[i]);
	}
	return 0;
}