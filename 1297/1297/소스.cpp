/*
2016.9.22
BaekJoon Online Judge
Problem Solving

Seong Joon Seo (ID: jjunCoder)

Problem
#1297
TV 크기
*/

#include <iostream>
#include <cmath>

using namespace std;

int main() {
	double a, h, w;
	cin.sync_with_stdio(false);
	cin >> a >> h >> w;
	double k;
	k = sqrt(a*a / (h*h + w*w));
	printf("%d %d", (int)floor(h*k), (int)floor(w*k));
	return 0;
}