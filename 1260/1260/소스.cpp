/*
2016.8.25
BaekJoon Online Judge
Problem Solving

Seong Joon Seo (ID: jjunCoder)

Problem
#1260
DFS�� BFS
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<bool> > map;
vector<bool> visited;
int n; // ������ ����
queue<int> q;

void DFS(int cur) {
	visited[cur] = true;
	printf("%d ", cur);
	for (int i = 1; i <= n; i++)
		if (map[cur][i] && !visited[i])
			DFS(i);
}

void BFS(int cur) {
	visited[cur] = true;
	q.push(cur);	
	while (!q.empty()) {		
		printf("%d ", cur);
		for(int i=1;i<=n;i++)
			if (map[cur][i] && !visited[i]) {
				visited[i] = true;
				q.push(i);
			}
		q.pop();
		if(!q.empty())
			cur = q.front();
	}
}

int main() {
	int m, v, x, y;
	cin.sync_with_stdio(false);
	cin >> n >> m >> v;
	map.assign(n + 1, vector<bool>(n + 1, false));
	visited.assign(n + 1, false);
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		map[x][y] = true;
		//ó������ �Ʒ� �ڵ� �� ���� ���� �ʾƼ� Ʋ�ȴ�. �̰� ������ �ܹ��� �׷��� �̴�.
		map[y][x] = true;
	}
	DFS(v);
	printf("\n");
	visited.clear();
	visited.assign(n + 1, false);
	BFS(v);
	return 0;
}