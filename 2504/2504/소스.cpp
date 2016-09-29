/*
2016.9.29
BaekJoon Online Judge
Problem Solving

Seong Joon Seo (ID: jjunCoder)

Problem
#2504
괄호의 값
*/

#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
	string input;
	cin.sync_with_stdio(false);
	cin >> input;
	stack<char> s;
	stack<int> cal, ret;
	bool mul = false;
	auto it = input.begin();
	while (it != input.end()) {
		if (*it == '(' || *it == '[') {
			//괄호가 열린다.
			
			mul = false;
			s.push(*(it++));
		}
		else {
			if (s.empty()) {
				//올바르지 못한 상황.
				printf("0");
				return 0;
			}
			else {
				//괄호가 닫힌다.				
				int cScore, calTemp;
				s.top() == '(' ? cScore = 2 : cScore = 3;
				if (s.top() == '(' || s.top() == '[') {
					if (mul) {
						//괄호 안에 괄호가 있는 경우. 곱셈
						s.pop();
						if (s.empty()) {
							calTemp = 0;
							while (!cal.empty()) {//한 덩어리의 괄호 묶음 계산을 끝낸다.
								calTemp += cal.top();
								cal.pop();
							}
							ret.push(calTemp*cScore);
						}
						if (!cal.empty()) {
							calTemp = cal.top();
							cal.pop();
							cal.push(calTemp*cScore);
						}
					}
					else {
						//괄호와 괄호가 결합된 경우. 덧셈
						s.pop();
						cal.push(cScore);
					}
				}
				else {
					//올바르지 못한 상황.
					printf("0");
					return 0;
				}
				mul = true;
				it++;
			}
		}
	}
	if (!s.empty())
		printf("0");//올바르지 못한 상황.
	else {
		int retSum = 0;
		while (!ret.empty()) {
			retSum += ret.top();
			ret.pop();
		}
		printf("%d", retSum);
	}
	return 0;
}