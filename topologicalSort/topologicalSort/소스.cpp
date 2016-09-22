/*
2016.9.22

Seong Joon Seo (ID: jjunCoder)

종만북 위상정렬 예시 코드 연습.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

//인접행렬 그래프, 알파뱃과 알파뱃 사이의 우선순위를 나타내는 방향그래프이다.
vector<vector<int> > adj;

//seen: 방문 여부 표시, order: 정점들의 위상정렬 벡터
vector<int> seen, order;

void dfs(int here) {
	seen[here] = 1;
	for (int there = 0; there < adj.size(); there++)
		if (adj[here][there] && !seen[there])
			dfs(there);
	order.push_back(here);
}

vector<int> topologicalSort() {
	int n = adj.size();
	seen = vector<int>(n, 0);
	order.clear();
	//방문하지 않은 모든 정점에 대해서 dfs를 돌린다.
	for (int i = 0; i < n; i++) if (!seen[i]) dfs(i);
	//dfs방문 결과를 역순으로 배열하면 위상 정렬을 얻게 된다.
	reverse(order.begin(), order.end());
	//만약 그래프에 사이클이 없다면 위상 정렬 성공.
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			if (adj[order[j]][order[i]])
				return vector<int>();//사이클이 있다면 비어있는 vector를 반환.
	return order;
}

//그래프를 만든다.
void makeGraph(const vector<string>& words) {
	//26*26의 2차원 배열을 초기화한다.
	adj = vector<vector<int> >(26, vector<int>(26, 0));
	//입력받은 전체 단어들에 대해서
	for (int j = 1; j < words.size(); j++) {
		//인접한 두 단어 중 짧은 길이를 고른다.
		int i = j - 1, len = min(words[i].size(), words[j].size());
		for (int k = 0; k < len; k++) {
			if (words[i][k] != words[j][k]) {
				//두 단어의 알파뱃중 첫번째로 다른게 나온다면
				int a = words[i][k] - 'a';//ascii code 를 몰라도 이런 방식으로 알파벳을 숫자화 가능.
				int b = words[j][k] - 'a';
				adj[a][b] = 1;//a->b로 간선을 추가한다. 즉 a가 b보다 우선순위인 것이다.
				break;
			}
		}
	}
}

int main() {
	int c;
	cin.sync_with_stdio(false);
	cin >> c;
	for (int i = 0; i < c; i++) {
		int n;
		string input;
		vector<string> words;
		cin >> n;
		for (int j = 0; j < n; j++) {
			cin >> input;
			words.push_back(input);
		}
		makeGraph(words);
	}
	vector<int> v = topologicalSort();
	for (int i = 0; i < v.size(); i++) {
		cout << (char)(v[i] + 'a');
	}
	return 0;
}