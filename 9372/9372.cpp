#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int, int> II;
#define X first
#define Y second

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
            return;
        parent[u] = v;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t, n, m, a, b;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        vector<II> edges;
        DisjointSet ds(n + 1);
        int ret = 0;
        for (int i = 0; i < m; i++)
        {
            cin >> a >> b;
            edges.push_back({a, b});
        }
        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i].X;
            int v = edges[i].Y;
            if (ds.find(u) != ds.find(v))
            {
                ds.merge(u, v);
                ret++;
            }
        }
        cout << ret << "\n";
    }
    return 0;
}