/*
2016.9.27
BaekJoon Online Judge
Problem Solving

Seong Joon Seo (ID: jjunCoder)

Problem
#9465
스티커
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int t, n, input;
	cin.sync_with_stdio(false);
	cin >> t;
	while (t--) {
		cin >> n;
		vector<vector<int> > board;
		board.assign(n, vector<int>(2, 0));
		for (int j = 0; j < 2; j++) {
			for (int i = 0; i < n; i++) {
				cin >> input;
				board[j][i] = input;
			}
		}
		
	}
	return 0;
}