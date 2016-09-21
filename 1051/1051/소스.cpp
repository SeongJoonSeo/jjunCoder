/*
2016.9.21
BaekJoon Online Judge
Problem Solving

Seong Joon Seo (ID: jjunCoder)

Problem
#1051
숫자 정사각형
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


int main() {
	int n, m;
	vector<vector<int> > v;
	string input;
	cin.sync_with_stdio(false);
	cin >> n >> m;	
	v.assign(n, vector<int>(m, -1));
	for (int i = 0; i < n; i++) {
		cin >> input;
		for (int j = 0; j < m; j++) {
			v[i][j] = input[j]-48;
		}
	}
	int len = min(n, m);
	int maxi = 1;
	for (int i = 1; i <= len; i++) {
		for (int y = 0; y + i < n; y++) {
			for (int x = 0; x + i < m; x++) {
				int a, b, c, d;
				a = v[y][x]; b = v[y + i][x]; c = v[y][x + i]; d = v[y + i][x + i];
				if (a == b&&b == c&&c == d) {
					maxi = max(maxi, (i+1)*(i+1));
				}
			}
		}
	}
	cout << maxi;
	return 0;
}