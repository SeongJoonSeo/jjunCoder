/*
2016.9.12
BaekJoon Online Judge
Problem Solving

Seong Joon Seo (ID: jjunCoder)

Problem
#11286
절대값 힙
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>

using namespace std;

int main() {
	int n, x;
	cin.sync_with_stdio(false);
	cin >> n;
	//양수는 minHeap에 넣으면 top이 절대값이 가장 작다.
	//음수는 maxHeap에 넣으면 top이 절대값이 가장 작다.
	priority_queue<int, vector<int>, less<int> > maxHeap;
	priority_queue<int, vector<int>, greater<int> > minHeap;
	for (int i = 0; i < n; i++) {
		cin >> x;
		if (x == 0) {
			if (minHeap.empty()&&maxHeap.empty()) {
				printf("%d\n", 0);
			}
			else {				
				if (maxHeap.empty()) {
					printf("%d\n", minHeap.top());
					minHeap.pop();
				}
				else if(minHeap.empty()){
					printf("%d\n", maxHeap.top());
					maxHeap.pop();
				}
				else {
					//a는 음수이고 b는 양수이다				
					int a = maxHeap.top();
					int b = minHeap.top();
					if (-a < b || -a == b) {
						printf("%d\n", a);
						maxHeap.pop();
					}
					else {
						printf("%d\n", b);
						minHeap.pop();
					}
				}
			}
		}
		else {
			if (x > 0) 
				minHeap.push(x);		
			else 
				maxHeap.push(x);
		}
	}
	return 0;
}