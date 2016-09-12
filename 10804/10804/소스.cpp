/*
2016.9.12
BaekJoon Online Judge
Problem Solving

Seong Joon Seo (ID: jjunCoder)

Problem
#10804
카드 역배치
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<int> cards;
	int a, b;
	cin.sync_with_stdio(false);
	for (int i = 0; i < 21; i++)
		cards.push_back(i);	
	for (int i = 0; i < 10; i++) {
		cin >> a >> b;
		reverse(cards.begin() + a, cards.begin() + b + 1);
	}
	for (auto it = cards.begin() + 1; it != cards.end(); it++)
		printf("%d ", *it);
	return 0;
}