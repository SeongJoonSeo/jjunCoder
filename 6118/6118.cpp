// BOJ 6118번: 숨바꼭질

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

vector<int> d;
vector<vector<int>> graph;

void djikstra(int start)
{
    queue<int> q;
    q.push(start);

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (int i = 0; i < graph[cur].size(); i++)
        {
            int next = graph[cur][i];
            if (!d[next])
            {
                d[next] = d[cur] + 1;
                q.push(next);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, a, b;
    cin >> n >> m;
    d.assign(n + 1, 0);
    graph.assign(n + 1, vector<int>());
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    djikstra(1);

    int maxDist = -1;
    int targetNum = 20001;
    int count = 0;
    for (int i = 2; i <= n; i++)
    {
        if (d[i] > maxDist)
        {
            maxDist = d[i];
        }
    }

    for (int i = 2; i <= n; i++)
    {
        if (d[i] == maxDist)
        {
            targetNum = min(targetNum, i);
            count++;
        }
    }

    cout << targetNum << " " << maxDist << " " << count << endl;

    return 0;
}
