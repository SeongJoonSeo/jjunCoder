// BOJ 2098번: 외판원 순회
#include <limits.h>

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define INF 16000001

int n, visitedAll;
vector<vector<int>> graph, dp;
// dp[cur][visited] -> 내 위치가 cur이고 지금까지 visited한 곳 : 최대 16개의 도시 : 111...1 은 모두 방문한거 -> 2^16 = 65,536

void setting();
void solve();
int travel(int cur, int visited);

int main() {
    setting();
    solve();
    return 0;
}

void setting() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    visitedAll = (1 << n) - 1;
    graph.assign(n, vector<int>(n, 0));
    dp.assign(n, vector<int>((1 << 16), 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> graph[i][j];
}

void solve() {
    cout << travel(0, 1) << endl;
}

bool isVisited(int visited, int next) {
    return visited & (1 << next);
}

int travel(int cur, int visited) {
    if (visited == visitedAll) {
        if (graph[cur][0])
            return graph[cur][0];
        else
            return INF;
    }
    int &ret = dp[cur][visited];
    if (ret != 0) return ret;

    ret = INF;
    for (int next = 1; next < n; next++) {
        if (!isVisited(visited, next) && graph[cur][next] != 0)
            ret = min(ret, travel(next, visited | (1 << next)) + graph[cur][next]);
    }

    return ret;
}