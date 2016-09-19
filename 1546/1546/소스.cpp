/*
2016.9.19
BaekJoon Online Judge
Problem Solving

Seong Joon Seo (ID: jjunCoder)

Problem
#1546
평균
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, score;
	cin.sync_with_stdio(false);
	cin >> n;
	vector<double> v;
	for (int i = 0; i < n; i++) {
		cin >> score;
		v.push_back(score);
	}
	sort(v.begin(), v.end());
	double maxi = v.back();
	for (int i = 0; i < n; i++) {
		v[i] = (v[i] / maxi) * 100;
	}
	double sum = 0;
	for (int i = 0; i < n; i++) {
		sum += v[i];
	}
	printf("%.2f", sum / n);
	return 0;
}