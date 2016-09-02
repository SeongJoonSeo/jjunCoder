/*
2016.9.2
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

int ret = 0;
deque<int> deq; //원래의 덱
deque<int> que; //뽑아내야 할 원소가 저장된 덱

void decrease() {
	for (auto it = que.begin(); it != que.end(); it++) {
		(*it)--;
		if ((*it) < 0) (*it) = deq.size() - 1;
	}
}

void increase() {
	for (auto it = que.begin(); it != que.end(); it++) {
		(*it)++;
		if ((*it) == deq.size()) (*it) = 0;
	}
}
//index에 있는 원소를 뽑는 함수.
void solve(int index) {
	if (index < deq.size() / 2) {
		//왼쪽으로 뽑아낸다.
		for (int i = 0; i < index; i++) {
			decrease();
			deq.push_back(deq.front());
			deq.pop_front();
			ret++;
		}
		deq.pop_front();
		que.pop_front();
		for (auto it = que.begin(); it != que.end(); it++)
			(*it)--;
	}
	else {
		//오른쪽으로 뽑아낸다.
		int temp = deq.size() - index - 1;
		for (int i = 0; i < temp; i++) {
			increase();
			deq.push_front(deq.back());
			deq.pop_back();
			ret++;
		}
		deq.pop_back();
		que.pop_front();
		for (auto it = que.begin(); it != que.end(); it++)
			(*it)++;
	}
}

int main() {
	int n, m, input, count = 0;
	cin.sync_with_stdio(false);
	cin >> n >> m;	
	for (int i = 0; i < n; i++) {
		deq.push_back(i);
	}
	for (int i = 0; i < m; i++) {
		cin >> input;
		que.push_back(input - 1);//1을 빼는 이유는 인덱스 형식으로 저장하기 위함이다.
	}
	while (!que.empty()) {
		solve(que.front());
	}
	cout << ret;
	return 0;
}