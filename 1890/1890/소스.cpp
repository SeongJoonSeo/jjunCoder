/*
2016.8.31
BaekJoon Online Judge
Problem Solving

Seong Joon Seo (ID: jjunCoder)

Problem
#1890
점프
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int> > dp, board;

int boardSize;
long long counting = 0;

int jump(int y, int x) {
	if (y >= boardSize || x >= boardSize)
		return false;
	if (y == boardSize - 1 && x == boardSize - 1) {
		counting++;
		return true;
	}
	int& ret = dp[y][x];
	if (ret == false) return ret;
	ret = false;
	ret |= jump(y + board[y][x], x);
	return ret |= jump(y, x + board[y][x]);
}

int main() {
	int n, cost;
	cin.sync_with_stdio(false);
	cin >> n;
	boardSize = n;
	board.assign(n, vector<int>(n, 0));
	dp.assign(n, vector<int>(n, -1));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> cost;
			board[i][j] = cost;
		}		
	}
	jump(0,0);
	cout << counting;
	return 0;
}