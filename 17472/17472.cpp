#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int n, m;
int V = 0;
const int MAX_V = 100;
bool impossible = false;
//u 와 연결된 v,w (w는 가중치)
vector<pair<int, int>> adj[MAX_V];
vector<vector<int>> board;

struct UnionFind
{
    vector<int> parent, rank;
    UnionFind(int n) : parent(n), rank(n, 1)
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
        if (rank[u] > rank[v])
            swap(u, v);
        parent[u] = v;
        if (rank[u] == rank[v])
            ++rank[v];
    }
};

void setting();
void printBoard();
void makeGraph();
void dfs(int r, int c);
int kruskal(vector<pair<int, int>> &selected);

int main()
{
    int s;
    cin >> n >> m;

    board.assign(n, vector<int>(m, 0));
    bool allOne = true;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> s;
            if (s == 0)
                allOne = false;
            board[i][j] = s;
        }
    }
    if (allOne)
    {
        cout << 0 << endl;
        return 0;
    }
    setting();
    makeGraph();
    vector<pair<int, int>> selected;
    int ret = kruskal(selected);
    if (impossible)
        ret = -1;
    cout << ret << endl;
    return 0;
}

void setting()
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            if (board[i][j] == 1)
            {
                ++V;
                dfs(i, j);
            }
        }
    }
    // printBoard();
}

bool isIn(int r, int c)
{
    return (0 <= r && r < n && 0 <= c && c < m);
}

const int dir[4][2] = {{-1, 0},
                       {1, 0},
                       {0, -1},
                       {0, 1}};
void dfs(int r, int c)
{
    board[r][c] = V + 1;
    for (int i = 0; i < 4; i++)
    {
        int nr = r + dir[i][0];
        int nc = c + dir[i][1];
        if (isIn(nr, nc) && board[nr][nc] == 1)
            dfs(nr, nc);
    }
}

void printBoard()
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << "----------" << endl;
}

// 정점 v, 가중치 w를 리턴
pair<int, int> getEdge(int u, int r, int c, int rdir, int cdir, int w)
{
    int nr = r + rdir;
    int nc = c + cdir;
    int v;
    if (isIn(nr, nc))
        v = board[nr][nc];
    else
        return make_pair(-1, -1);

    if (v == u)
        return make_pair(-1, -1);

    if (v != 0 && w <= 1)
        return make_pair(-1, -1);

    if (v != 0)
        return make_pair(v - 2, w);

    return getEdge(u, nr, nc, rdir, cdir, w + 1);
}

void makeGraph()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            //정점 u는 나중에 저장할때 2를 빼고 저장한다.
            int u = board[i][j];
            if (u != 0)
            {
                for (int k = 0; k < 4; k++)
                {
                    int rdir = dir[k][0];
                    int cdir = dir[k][1];
                    if (u == 2 && rdir == 0 && cdir == -1)
                    {
                        int asd = 1;
                    }
                    pair<int, int> e = getEdge(u, i, j, rdir, cdir, 0);
                    if (e != make_pair(-1, -1))
                    {
                        adj[u - 2].push_back(e);
                    }
                }
            }
        }
    }
}

int kruskal(vector<pair<int, int>> &selected)
{
    int ret = 0;
    selected.clear();
    vector<pair<int, pair<int, int>>> edges;
    UnionFind sets(V);

    for (int u = 0; u < V; u++)
    {
        for (int i = 0; i < adj[u].size(); i++)
        {
            int v = adj[u][i].first;
            int cost = adj[u][i].second;
            edges.push_back(make_pair(cost, make_pair(u, v)));
        }
    }
    sort(edges.begin(), edges.end());
    for (int i = 0; i < edges.size(); i++)
    {
        int cost = edges[i].first;
        int u = edges[i].second.first;
        int v = edges[i].second.second;
        if (sets.find(u) == sets.find(v))
            continue;
        sets.merge(u, v);
        ret += cost;
        selected.push_back(make_pair(u, v));
    }
    set<int> setNums;
    for (int i = 0; i < V; i++)
        setNums.insert(sets.find(i));
    if (setNums.size() != 1)
        impossible = true;
    return ret;
}