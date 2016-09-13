/*
2016.
BaekJoon Online Judge
Problem Solving

Seong Joon Seo (ID: jjunCoder)

Problem
#1927
최소 힙
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

int main() {
	int n;
	cin.sync_with_stdio(false);
	cin >> n;
	int x;
	priority_queue<int,vector<int>,greater<int> > minHeap;
	for (int i = 0; i < n; i++) {
		cin >> x;
		if (x == 0) {
			if (minHeap.empty())
				printf("%d\n",0);
			else {
				printf("%d\n", minHeap.top());
				minHeap.pop();
			}
		}
		else {
			minHeap.push(x);
		}
	}
	return 0;
}