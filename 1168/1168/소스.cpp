/*
2016.9.29
BaekJoon Online Judge
Problem Solving

Seong Joon Seo (ID: jjunCoder)

Problem
#1168
조세퍼스 문제 2
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

vector<int> ret;

void josephus(int n, int m) {
	int originSize = n;
	list<int> linkedList;
	for (int i = 1; i <= n; i++)
		linkedList.push_back(i);
	auto kill = linkedList.begin();
	while (n > 0) {
		for (int i = 0; i < (m - 1) % originSize; i++) {
			kill++;
			if (kill == linkedList.end())
				kill = linkedList.begin();
		}
		ret.push_back(*kill);
		kill = linkedList.erase(kill);
		if (kill == linkedList.end())
			kill = linkedList.begin();
		n--;
	}
	return;
}

int main() {
	int n, m;
	cin.sync_with_stdio(false);
	cin >> n >> m;
	josephus(n, m);
	printf("<");
	for (auto it = ret.begin(); it != ret.end() - 1; it++)
		printf("%d, ", *it);
	printf("%d>", *(ret.end() - 1));
	return 0;
}