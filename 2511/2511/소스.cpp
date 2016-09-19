/*
2016.9.19
BaekJoon Online Judge
Problem Solving

Seong Joon Seo (ID: jjunCoder)

Problem
#2511
카드놀이
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<int> a, b;
	int card;
	for (int i = 0; i < 10; i++) {
		cin >> card;
		a.push_back(card);
	}
	for (int i = 0; i < 10; i++) {
		cin >> card;
		b.push_back(card);
	}
	int last = -1;
	int A = 0, B = 0;
	for (int i = 0; i < 10; i++) {
		if (a[i] > b[i]) {
			A += 3; last = 0;
		}
		else if (a[i] < b[i]) {
			B += 3; last = 1;
		}
		else {
			A++; B++;
		}
	}
	if (last == -1) {
		//비긴 경우, 점수는 둘다 10점이고 D를 출력
		cout << "10 10\nD";
	}
	else {
		if (A != B) {
			cout << A << " " << B << endl;
			if (A > B)
				cout << "A";
			else
				cout << "B";
		}
		else {
			if (last == 0) {
				//A가 승
				cout << A << " " << B << endl << "A";
			}
			else {
				cout << A << " " << B << endl << "B";
			}
		}		
	}
	return 0;
}