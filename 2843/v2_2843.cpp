// 2843 마블 2트

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int, int> II;

struct DisjointSet
{
    vector<int> parent;
    DisjointSet(int n) : parent(n)
    {
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }
    int find(int u)
    {
        if (parent[u] == u)
            return u;
        return parent[u] = find(parent[u]);
    }
    void merge(int u, int v)
    {
        u = find(u);
        v = find(v);
        if (u == v)
        {
            parent[u] = 0;
            return;
        }
        parent[u] = v;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, Q, q, u;
    cin >> n;

    DisjointSet ds(n + 1);

    vector<int> connected(n + 1, 1), graph(n + 1, 0);
    vector<II> queries;

    for (int i = 1; i <= n; i++)
    {
        cin >> graph[i];
    }
    cin >> Q;
    for (int i = 0; i < Q; i++)
    {
        cin >> q >> u;
        queries.push_back({q, u});
        if (q == 2)
            connected[u] = 0;
    }
    for (int u = 1; u <= n; u++)
    {
        if (connected[u] == 1 && graph[u] != 0)
        {
            int v = graph[u];
            ds.merge(u, v);
        }
    }
    vector<int> res;
    for (int i = Q - 1; i >= 0; i--)
    {
        int u = queries[i].second;
        if (queries[i].first == 1)
        {
            res.push_back(ds.find(u));
        }
        else
        {
            int v = graph[u];
            if (v != 0)
                ds.merge(u, v);
        }
    }

    for (int i = res.size() - 1; i >= 0; i--)
        if (res[i] == 0)
            printf("CIKLUS\n");
        else
            printf("%d\n", res[i]);
    return 0;
}