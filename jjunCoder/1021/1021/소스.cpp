/*
2016.8.26
BaekJoon Online Judge
Problem Solving

Seong Joon Seo (ID: jjunCoder)

Problem
#1021
회전하는 큐
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>

using namespace std;

auto middle(deque<int>& deq) {
	auto it = deq.begin();
	for (int i = 0; i < deq.size() / 2; i++) {
		++it;
	}
	if (deq.size() % 2 == 0)
		return it - 1;
	else
		return it;
}

int main() {
	int n, m, input, count = 0;
	cin.sync_with_stdio(false);
	cin >> n >> m;
	deque<int> deq;
	deque<int> que;
	for (int i = 0; i < n; i++) {
		deq.push_back(i + 1);
	}
	for (int i = 0; i < m; i++) {
		cin >> input;
		que.push_back(input);
	}
	for (int i = 0; i < m; i++) {
		auto it = find(deq.begin(), deq.end(), que.front());		
		if (it <= middle(deq)) {
			while (it != deq.begin()) {
				deq.push_back(deq.front());
				deq.pop_front();
				it = find(deq.begin(), deq.end(), que.front());
				count++;
			}
			deq.pop_front();
			que.pop_front();
		}
		else if (it > middle(deq)) {
			while (it != deq.end()-1) {
				deq.push_front(deq.back());
				deq.pop_back();
				it = find(deq.begin(), deq.end(), que.front());
				count++;
			}
			deq.pop_back();
			que.pop_front();
		}
	}
	cout << count;
	return 0;
}