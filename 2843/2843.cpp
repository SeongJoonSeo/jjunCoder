#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

#define CHECK 1
#define DELETE 2

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
            parent[u] = parent[v] = 0;
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
    int n, to, q, query, v;
    cin >> n;
    DisjointSet ds = DisjointSet(n + 1);
    vector<int> graph(n + 1, 0), res;
    vector<bool> connected(n + 1, true);
    vector<pair<int, int>> queries;

    for (int i = 1; i <= n; i++)
        cin >> graph[i];
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        cin >> query >> v;
        queries.push_back({query, v});
        if (query == DELETE)
            connected[v] = false;
    }
    for (int i = 1; i <= n; i++)
    {
        if (connected[i] && graph[i] != 0)
            ds.merge(i, graph[i]);
    }

    for (int i = queries.size() - 1; i >= 0; i--)
    {
        if (queries[i].first == CHECK)
        {
            int u = ds.find(queries[i].second);
            res.push_back(u);
        }
        else
        {
            int u = queries[i].second;
            int v = graph[u];
            ds.merge(u, v);
        }
    }
    for (int i = res.size() - 1; i >= 0; i--)
    {
        if (res[i] == 0)
            cout << "CIKLUS\n";
        else
            cout << res[i] << "\n";
    }
    return 0;
}