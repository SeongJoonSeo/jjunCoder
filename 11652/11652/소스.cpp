/*
2016.9.13
BaekJoon Online Judge
Problem Solving

Seong Joon Seo (ID: jjunCoder)

Problem
#11652
카드
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
	int n;
	cin.sync_with_stdio(false);
	cin >> n;
	long long num;
	map<long long, int> m;
	int maxi = -1;
	long long ret;
	for (int i = 0; i < n; i++) {
		cin >> num;
		auto it = m.find(num);
		if (it != m.end()) {
			(*it).second++;
			if (maxi < (*it).second) {
				maxi = (*it).second;
				ret = (*it).first;
			}
			else if (maxi == (*it).second) {
				maxi = (*it).second;
				ret = min(ret, (*it).first);
			}
		}
		else {
			m.insert(make_pair(num, 0));
		}
	}
	cout << ret;
	return 0;
}