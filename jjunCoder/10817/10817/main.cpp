/*
2016.8.22
BaekJoon Online Judge
Problem Solving

Seong Joon Seo (ID: jjunCoder)

Problem
#10817
¼¼ ¼ö
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int a, b, c, ret;
	cin >> a >> b >> c;
	vector<int> v;
	v.push_back(a);
	v.push_back(b);
	v.push_back(c);
	sort(v.begin(), v.end());
	cout << v[1];
	return 0;
}