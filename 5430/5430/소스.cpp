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
#include <string>

using namespace std;

int main() {
	int t;
	cin.sync_with_stdio(false);
	cin >> t;	
	
	for (int i = 0; i < t; i++) {
		int num = 0, radix = 0, n, m, input;
		bool mode = true;
		char c;
		deque<int> deq;		
		string p;
		cin >> p >> n;

		cin >> c;// '['소거
		while (c != ']') {
			if (n == 0) {
				cin >> c;// ']'소거
				break;
			}				
			cin >> input;
			deq.push_back(input);
			cin >> c;// ','소거
		}

		//p 명령어를 본다.
		for (int j = 0; j < p.size(); j++) {
			if (p[j] == 'R')
				mode = !mode;			
			else {// D
				if (mode) {
					if (deq.empty()) {
						printf("error");
						break;
					}
					else
						deq.pop_front();
				}
				else {
					if (deq.empty()) {
						printf("error");
						break;
					}
					else
						deq.pop_back();
				}
			}
		}

		m = deq.size();
		if (!deq.empty()) {
			if (mode) {
				printf("[");				
				for (int j = 0; j < m - 1; j++) {
					printf("%d,", deq.front());
					deq.pop_front();
				}
				printf("%d]", deq.front());
			}
			else {
				printf("[");
				for (int j = 0; j < m - 1; j++) {
					printf("%d,", deq.back());
					deq.pop_back();
				}
				printf("%d]", deq.back());
			}
		}
		if (i != t - 1)
			printf("\n");
	}
	return 0;
}