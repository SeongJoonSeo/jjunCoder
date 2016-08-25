/*
2016.8.25
BaekJoon Online Judge
Problem Solving

Seong Joon Seo (ID: jjunCoder)

Problem
#1260
DFS와 BFS
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<bool> > map;
vector<bool> visited;
int n; // 정점의 개수
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
		//처음에는 아래 코드 한 줄을 쓰지 않아서 틀렸다. 이게 없으면 단방향 그래프 이다.
		map[y][x] = true;
	}
	DFS(v);
	printf("\n");
	visited.clear();
	visited.assign(n + 1, false);
	BFS(v);
	return 0;
}