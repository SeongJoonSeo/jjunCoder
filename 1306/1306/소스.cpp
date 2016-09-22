/*
2016.9.22
BaekJoon Online Judge
Problem Solving

Seong Joon Seo (ID: jjunCoder)

Problem
#1306
달려라 홍준
*/

#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

int main() {
	int n, m;
	cin.sync_with_stdio(false);
	cin >> n >> m;
	int light,maxi = -1;
	int s;
	if (2 * m - 1 <= n)
		s = 2 * m - 1;
	else
		s = n;
	deque<int> deq;
	for (int i = 0; i < s ; i++) {
		cin >> light;		
		deq.push_back(light);
	}
	auto it = max_element(deq.begin(), deq.end());	
	printf("%d ", *it);
	while (cin >> light) {
		if (deq.begin() == it) {
			deq.pop_front();
			deq.push_back(light);
			it = max_element(deq.begin(), deq.end());			
		}
		else {
			if (*it < light)
				it = deq.end() - 1;
			deq.pop_front();
			
			deq.push_back(light);
		}
			
		printf("%d ", *it);
	}

	return 0;
}