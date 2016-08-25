/*
2016.8.25
BaekJoon Online Judge
Problem Solving

Seong Joon Seo (ID: jjunCoder)

Problem
#1966
프린터 큐
*/

#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int t, n, m, p, count = 0;
	deque<int> q;
	vector<int> v;
	int it;
	cin.sync_with_stdio(false);
	cin >> t;
	for (int i = 0; i < t; i++) {
		count = 0;
		q.clear();
		v.clear();
		cin >> n >> m;
		for (int j = 0; j < n; j++) {
			cin >> p;
			q.push_back(p);
			v.push_back(p);
		}
		sort(v.begin(), v.end());
		it = m;
		while (true) {
			if (it == 0 && q[it] == v.back()) {
				printf("%d\n", count + 1);				
				break;
			}
			if (q.front() == v.back()) {
				q.pop_front();
				v.pop_back();
				count++;
				it--;
			}
			else {				
				q.push_back(q.front());
				q.pop_front();
				if (it == 0)
					it = q.size() - 1;
				else
					it--;
			}
		}
	}
	return 0;
}