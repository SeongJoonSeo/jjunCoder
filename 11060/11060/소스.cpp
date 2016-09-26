/*
2016.9.26
BaekJoon Online Judge
Problem Solving

Seong Joon Seo (ID: jjunCoder)

Problem
#11060
점프 점프
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> maze;
vector<int> dp;

const int INF = 987654321;

int solve(int i) {	
	if (i == maze.size() - 1) //가장 오른쪽 칸.
		return 0;	
	else if (i >= maze.size()) //오른쪽을 넘어가면 불가능.
		return INF;
	if (maze[i] == 0) //그 칸에서 움직일 수 없으면 불가능.
		return INF;
	int& ret = dp[i];
	if (ret != -1) return ret;
	int mini = INF;
	for (int j = 1; j <= maze[i]; j++) {
		mini = min(mini, solve(i + j) + 1);
	}
	return ret = mini;
}

int main() {
	int n, input;
	cin.sync_with_stdio(false);
	cin >> n;
	maze.assign(n, 0);
	dp.assign(n, -1);
	for (int i = 0; i < n; i++) {
		cin >> input;
		maze[i] = input;
	}
	int ret = solve(0);
	if (ret == INF)
		cout << -1;
	else
		cout << ret;
	return 0;
}