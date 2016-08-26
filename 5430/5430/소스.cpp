/*
2016.8.26
BaekJoon Online Judge
Problem Solving

Seong Joon Seo (ID: jjunCoder)

Problem
#5430
AC
*/

#include <iostream>
#include <deque>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

int main() {
	int t, n, m, input;
	bool pushFront = true;
	char c;
	string p;
	cin.sync_with_stdio(false);
	cin >> t;	
	
	for (int i = 0; i < t; i++) {
		int num = 0, radix = 0;
		deque<int> deq;		
		cin >> p >> n;
		scanf("%c", &c);// '['소거
		while (c != ']') {
			if (n == 0) {
				scanf("%c", &c);// ']'소거
				break;
			}				
			scanf("%d", &input);
			deq.push_back(input);
			scanf("%c", &c);// ','소거
		}
		
		for (int i = 0; i < p.size(); i++) {
			if (p[i] == 'R') {
				reverse(deq.begin(), deq.end());
			}
			else if (p[i] == 'D') {
				if (deq.empty()) {
					cout << "error" << endl;
					break;
				}
				else
					deq.pop_front();
			}
		}
		if (!deq.empty()) {
			m = deq.size();
			printf("[");
			for (int i = 0; i < m - 1; i++) {
				printf("%d,", deq.front());
				deq.pop_front();
			}
			printf("%d]\n", deq.front());
			deq.pop_front();
		}		
	}
	return 0;
}