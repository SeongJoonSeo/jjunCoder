#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
int n, target;
int construction_time[1001];
vector<int> cnt,time_sum;
vector<vector<int>> graph;

void setting();
void topoSort();

int main()
{
    setting();
    return 0;
}

void setting()
{
    int t, k;
    cin >> t;
    for (int tc = 0; tc < t; tc++)
    {
        cin >> n >> k;
        time_sum.assign(n+1,0);
        cnt.assign(n+1,0);
        graph.assign(n+1, vector<int>());
        for (int i = 1; i <= n; i++)
            cin >> construction_time[i];
        for (int i = 0; i < k; i++)
        {
            int a, b;
            scanf("%d %d", &a, &b);
            graph[a].push_back(b);
            cnt[b]++;
        }
        cin >> target;
        topoSort();
        cout << time_sum[target] << endl;
    }
}

void topoSort()
{
    queue<int> q;
    for (int i = 1; i <= n; i++){
        time_sum[i]=construction_time[i];
        if (cnt[i] == 0)
            q.push(i);
    }

    int cur = 0;
    while (!q.empty())
    {
        cur = q.front();
        q.pop();
        if (cur == target)
            break;
        for (auto &next : graph[cur])
        {
            time_sum[next] = max(time_sum[next], time_sum[cur] + construction_time[next]);
            cnt[next]--;
            if(cnt[next]==0) {
                if(next==target) return;
                q.push(next);
            }
        }
    }
}