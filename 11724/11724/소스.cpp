/*
2016.9.22
BaekJoon Online Judge
Problem Solving

Seong Joon Seo (ID: jjunCoder)

Problem
#11724
연결 요소의 개수
*/

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > adj;
vector<bool> seen;

void dfs(int here) {
	seen[here] = true;
	for (int there= 0; there < adj.size(); there++) {
		if (adj[here][there] && !seen[there]) {
			dfs(there);
		}		
	}
}

int main() {
	int n, m, u, v;
	cin.sync_with_stdio(false);
	cin >> n >> m;
	adj.assign(n + 1, vector<int>(n + 1, 0));
	seen.assign(n + 1, false);
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		adj[u][v] = 1;
		adj[v][u] = 1;
	}
	int ret = 0;
	for (int i = 1; i <= n; i++) {
		if (!seen[i]) {
			dfs(i);
			ret++;
		}
	}
	cout << ret;
	return 0;
}