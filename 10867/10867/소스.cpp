/*
2016.9.12
BaekJoon Online Judge
Problem Solving

Seong Joon Seo (ID: jjunCoder)

Problem
#10867
중복 빼고 정렬하기
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {
	int n, num;
	cin.sync_with_stdio(false);
	cin >> n;
	set<int> s;
	for (int i = 0; i < n; i++) {
		cin >> num;
		s.insert(num);
	}
	
	for (auto it = s.begin(); it != s.end(); it++) {
		printf("%d ", *it);
	}
	return 0;
}