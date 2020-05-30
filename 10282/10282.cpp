// BOJ 10282번: 해킹
#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

typedef pair<int, int> II;
#define COST first
#define VERTEX second
#define COUNT second
#define INF 987654321

II dijkstra(int src, int n, vector<II> *graph) {
    int lastV = src;
    II result = {0, 0};
    priority_queue<II, vector<II>, greater<II>> pq;
    vector<int> dist(n + 1, INF);
    dist[src] = 0;
    pq.push({0, src});
    while (!pq.empty()) {
        int cost = pq.top().COST;
        int here = pq.top().VERTEX;
        pq.pop();
        if (dist[here] < cost)
            continue;
        result.COUNT++;
        lastV = here;
        for (int i = 0; i < graph[here].size(); i++) {
            int there = graph[here][i].VERTEX;
            int nextCost = graph[here][i].COST + dist[here];
            if (nextCost < dist[there]) {
                dist[there] = nextCost;
                pq.push({nextCost, there});
            }
        }
    }
    result.COST = dist[lastV];

    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, d, c;
        cin >> n >> d >> c;
        vector<II> graph[n + 1];
        for (int i = 0; i < d; i++) {
            int a, b, s;
            cin >> a >> b >> s;
            graph[b].push_back({s, a});
        }
        II res = dijkstra(c, n, graph);
        cout << res.COUNT << " " << res.COST << endl;
    }
    return 0;
}