/*
2016.9.22
BaekJoon Online Judge
Problem Solving

Seong Joon Seo (ID: jjunCoder)

Problem
#2178
미로 탐색
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<vector<int> > adj;
int n, m;

int dfs(int x, int y,int count) {
	adj[y][x] = 2;
	if (x == m - 1 && y == n - 1) {
		return count;
	}
	if (x + 1 < m && adj[y][x + 1] == 1)
		dfs(x + 1, y, count + 1);
	if (y + 1 < n && adj[y + 1][x] == 1)
		dfs(x, y + 1, count + 1);
	if (x - 1 >= 0 && adj[y][x - 1] == 1)
		dfs(x - 1, y, count + 1);
	if (y - 1 >= 0 && adj[y - 1][x] == 1)
		dfs(x, y - 1, count + 1);
		
}

int main() {	
	string input;
	cin.sync_with_stdio(false);
	cin >> n >> m;
	adj.assign(n, vector<int>(m, 0));
	for (int i = 0; i < n; i++) {
		cin >> input;
		for (int j = 0; j < m; j++) {
			adj[i][j] = input[j] - 48;
		}
	}

	cout << dfs(0, 0, 0);
	return 0;
}