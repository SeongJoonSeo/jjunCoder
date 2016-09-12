/*
2016.9.12
BaekJoon Online Judge
Problem Solving

Seong Joon Seo (ID: jjunCoder)

Problem
#11279
최대 힙
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int n, input;
	cin.sync_with_stdio(false);
	cin >> n;
	vector<int> myHeap;
	make_heap(myHeap.begin(), myHeap.end());
	for (int i = 0; i < n; i++) {
		cin >> input;
		if (!myHeap.empty() && input == 0){
			printf("%d\n", myHeap.front());
			pop_heap(myHeap.begin(), myHeap.end());
			myHeap.pop_back();
		}
		else if(myHeap.empty() && input == 0){
			printf("%d\n", 0);
		}
		else {
			myHeap.push_back(input);
			push_heap(myHeap.begin(), myHeap.end());
		}
	}
	return 0;
}