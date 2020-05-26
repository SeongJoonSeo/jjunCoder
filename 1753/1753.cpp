// BOJ 1753번: 최단경로
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> II;
#define COST first
#define VERTEX second
#define INF 987654321

const int MAX_V = 20001, MAX_E = 300001;
int V, E, src;
vector<II> adj[MAX_V];

void setting();
void dijkstra();

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    setting();
    dijkstra();
    return 0;
}

void setting()
{
    cin >> V >> E >> src;
    int u, v, w;
    for (int i = 0; i < E; i++)
    {
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
    }
}

void dijkstra()
{
    vector<int> dist(V + 1, INF);
    dist[src] = 0;
    priority_queue<II, vector<II>, greater<II>> pq;
    pq.push({0, src});
    while (!pq.empty())
    {
        int cost = pq.top().COST;
        int here = pq.top().VERTEX;
        pq.pop();
        if (dist[here] < cost)
            continue;
        for (int i = 0; i < adj[here].size(); i++)
        {
            int there = adj[here][i].VERTEX;
            int nextDist = adj[here][i].COST + cost;
            if (dist[there] > nextDist)
            {
                dist[there] = nextDist;
                pq.push({nextDist, there});
            }
        }
    }
    for (int i = 1; i <= V; i++)
    {
        if (dist[i] == INF)
            printf("INF\n");
        else
            printf("%d\n", dist[i]);
    }
}