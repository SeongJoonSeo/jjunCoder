#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int N, M, A, B;
    cin >> N >> M;
    vector<int> graph[N + 1];
    vector<int> cnt(N + 1, 0);
    for (int i = 0; i < M; i++)
    {
        cin >> A >> B;
        cnt[B]++;
        graph[A].push_back(B);
    }

    queue<int> q;
    for (int i = 1; i <= N; i++)
    {
        if (cnt[i] == 0)
            q.push(i);
    }
    vector<int> res;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        cout << cur << " ";
        for (int i = 0; i < graph[cur].size(); i++)
        {
            int next = graph[cur][i];
            cnt[next]--;
            if (cnt[next] == 0)
            {
                q.push(next);
            }
        }
    }
    return 0;
}