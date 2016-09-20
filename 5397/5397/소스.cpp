#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <stack>

using namespace std;

string ReverseString(const string src, int len)
{
	string reverse;

	for (int i = 0; i < len; i++)
		reverse += src.substr(len - i - 1, 1);

	return reverse;
}

void solve(const string& str) {
	stack<char> myStack, temp;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '<') {
			if (myStack.empty())
				continue;
			else {
				temp.push(myStack.top());
				myStack.pop();
			}
		}
		else if (str[i] == '>') {
			// if (myStack.empty())
			// 	continue;
			if (!temp.empty()) {
				myStack.push(temp.top());
				temp.pop();
			}
		}
		else if (str[i] == '-') {
			if (myStack.empty() && temp.empty())
				continue;
			else if (myStack.empty() && !temp.empty()) {

			}
			else
				myStack.pop();
		}
		else {
			myStack.push(str[i]);
		}
	}
	while (!temp.empty()) {
		myStack.push(temp.top());
		temp.pop();
	}
	string result = "";
	while (!myStack.empty()) {
		result += myStack.top();
		myStack.pop();
	}

	cout << ReverseString(result, result.length()) << endl;

	return;
}

int main() {
	int n;
	cin >> n;
	string input;

	for (int i = 0; i < n; i++) {
		cin >> input;
		solve(input);
	}
	return 0;
}