/*
2016.8.22
BaekJoon Online Judge
Problem Solving

Seong Joon Seo (ID: jjunCoder)

Problem
#1287
할 수 있다
*/

#include <iostream>
#include <stack>
#include <string>

using namespace std;

string input;
stack<char> numbers, ops;
int num=-1,result;
char op='.';
int main() {	
	cin >> input;
	for (int i = 0; i < input.size(); i++) {
		if (input[i] >= 48 && input[i] <= 57) {
			numbers.push(input[i]);
			/*if(num==-1)
				num = input[i] - 48;
			else {
				if (op == '+') {
					result = num + (input[i] - 48);
				}
				else if (op == '-') {
					result = num - (input[i] - 48);
				}
				else if (op == '*') {
					result = num * (input[i] - 48);
				}
				else if (op == '/') {
					result = num / (input[i] - 48);
				}
				numbers.push(result);
			}*/
		}
		else if (input[i] == '(') {
			if (num != -1) {
				numbers.push(num);
				num = -1;
			}
			if (op != '.') {
				ops.push(op);
				op = '.';
			}
		}
		else if (input[i] == ')') {

		}
		else { // operations
			/*ops.push(input[i]);*/
			op = input[i];
		}
	}
	return 0;
}