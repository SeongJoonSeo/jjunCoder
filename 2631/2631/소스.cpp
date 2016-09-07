/*
2016.9.2
BaekJoon Online Judge
Problem Solving

Seong Joon Seo (ID: jjunCoder)

Problem
#2631
줄세우기
*/

#include <iostream>
#include <vector>
using namespace std;
vector<int> childeren;
int main() {
	int n, num;
	cin.sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		childeren.push_back(num);
	}
	return 0;
}