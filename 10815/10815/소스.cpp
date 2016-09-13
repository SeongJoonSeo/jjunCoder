/*
2016.9.13
BaekJoon Online Judge
Problem Solving

Seong Joon Seo (ID: jjunCoder)

Problem
#10815
숫자 카드
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {
	int n, num, m;
	cin.sync_with_stdio(false);
	cin >> n;
	set<int> s;
	for (int i = 0; i < n; i++) {
		cin >> num;
		s.insert(num);
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> num;
		if (s.find(num) != s.end()) 
			printf("%d ", 1);
		else
			printf("%d ", 0);		
	}
	return 0;
}