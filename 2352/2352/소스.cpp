/*
2016.9.7
BaekJoon Online Judge
Problem Solving

Seong Joon Seo (ID: jjunCoder)

Problem
#2352
반도체 설계
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
	int n, portNum, ret = 0;
	cin.sync_with_stdio(false);
	cin >> n;
	vector<pair<int,int>> ports;
	for (int i = 1; i <= n; i++) {
		cin >> portNum;
		ports.push_back(make_pair(abs(i - portNum), i));
	}
	sort(ports.begin(), ports.end());
	int idx = ports.front().second;
	for (int i = 0; i < n; i++) {
		ret++;
		idx = ports[i].second;
		if (idx == n) break;
	}
	cout << ret;
	return 0;
}