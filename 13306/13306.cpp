#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

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
    int n, q, query, u, v;
    cin >> n >> q;
    DisjointSet ds(n + 1);
    vector<int> graph(n + 1, 0), connected(n + 1, true), queries[3], res;

    for (int i = 0; i < 3; i++)
        queries[i].assign(n - 1 + q, 0);
    for (int i = 1; i <= n - 1; i++)
        cin >> graph[i + 1];
    for (int i = 0; i < n - 1 + q; i++)
    {
        cin >> queries[0][i];
        if (queries[0][i] == 0)
        {
            cin >> queries[1][i]; //u 엣지 제거
            connected[queries[1][i]] = false;
        }
        else
            cin >> queries[1][i] >> queries[2][i]; // u, v 연결하는 경로가 있는지 물어보는거
    }
    for (int i = 1; i <= n - 1; i++)
    {
        if (connected[i] && graph[i] != 0)
            ds.merge(i, graph[i]);
    }
    for (int i = queries[0].size() - 1; i >= 0; i--)
    {
        if (queries[0][i] == 0)
        {
            int u = queries[1][i];
            int v = graph[u];
            ds.merge(u, v);
        }
        else
        {
            int u = ds.find(queries[1][i]);
            int v = ds.find(queries[2][i]);
            if (u == v)
                res.push_back(1);
            else
                res.push_back(0);
        }
    }
    for (int i = res.size() - 1; i >= 0; i--)
    {
        if (res[i])
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}