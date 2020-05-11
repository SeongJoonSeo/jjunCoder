#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_set>

using namespace std;

int cluster_num = 0;
unordered_set<int> cluster;
int R, C;
char map[101][101];
vector<int> visited[101];

// void printMap();
// void printVisit();
void breakMineral(int h, int turn);
void clearVisit();
bool isIn(int r, int c);
void dfs(int r, int c);
void dfsDriver();
void solve(int h, int turn);
void floatProcess();

int dir[4][2] = {
    {-1, 0},
    {1, 0},
    {0, -1},
    {0, 1}};

int main()
{
    cin >> R >> C;
    char c;
    clearVisit();
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
        {
            cin >> c;
            map[i][j] = c;
        }
    dfsDriver();
    // cout << "First map" << endl;
    // printMap();
    int N, H;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        // cout << i << "th map" << endl;
        cin >> H;
        solve(R - H, i % 2);
    }
    // cout << "Last map" << endl;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (map[i][j] != '.')
                cout << 'x';
            else
                cout << '.';
        }
        cout << endl;
    }
    return 0;
}

void printVisit()
{
    // cout << "========================" << endl;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            // cout << visited[i][j];
        }
        // cout << endl;
    }
    // cout << "========================" << endl;
}

void printMap()
{
    // cout << "========================" << endl;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            // cout << map[i][j];
        }
        // cout << endl;
    }
    // cout << "========================" << endl;
}

bool isIn(int r, int c)
{
    return 0 <= r && r < R && 0 <= c && c < C;
}

void dfs(int r, int c)
{
    map[r][c] = cluster_num + '0';
    visited[r][c] = 1;
    for (int i = 0; i < 4; i++)
    {
        int nr = r + dir[i][0];
        int nc = c + dir[i][1];
        if (isIn(nr, nc) && map[nr][nc] != '.' && visited[nr][nc] == -1)
        {
            dfs(nr, nc);
        }
    }
}

void dfsDriver()
{
    cluster_num = 0;
    cluster.clear();
    for (int row = 0; row < R; row++)
    {
        for (int col = 0; col < C; col++)
        {
            if (visited[row][col] == -1 && map[row][col] != '.')
            {
                dfs(row, col);
                cluster.insert(cluster_num);
                cluster_num++;
            }
        }
    }
}

void solve(int h, int turn)
{
    breakMineral(h, turn);
    clearVisit();
    dfsDriver();
    floatProcess();
    // printMap();
}

void breakMineral(int h, int turn)
{
    if (turn == 0)
        for (int j = 0; j < C; j++)
        {
            char &item = map[h][j];
            if (item != '.')
            {
                item = '.';
                break;
            }
        }
    else
        for (int j = C - 1; j >= 0; j--)
        {
            char &item = map[h][j];
            if (item != '.')
            {
                item = '.';
                break;
            }
        }
}

void clearVisit()
{
    for (int i = 0; i < R; i++)
    {
        visited[i].assign(C, -1);
    }
}

void floatProcess()
{
    // 미네랄이 바닥에 있으면 바로 판별
    for (int col = 0; col < C; col++)
        if (map[R - 1][col] != '.')
            cluster.erase(map[R - 1][col] - '0');

    for (auto clusterNum : cluster)
    {
        int min_len = 101;
        vector<int> start_rows(C, 0);
        for (int col = 0; col < C; col++)
        {
            int len = 0;
            for (int row = R - 1; row >= 0; row--)
            {
                char curmineral = map[row][col];
                if (curmineral - '0' == clusterNum)
                {
                    start_rows[col] = row + len;
                    min_len = min(min_len, len);
                    break;
                }
                else if (curmineral == '.')
                    len++;
                else
                    len = 0;
            }
        }

        for (int j = 0; j < min_len; j++)
        {
            for (int col = 0; col < start_rows.size(); col++)
            {
                for (int row = start_rows[col]; row >= 0; row--)
                {
                    if ((map[row][col] == '.' || map[row][col] - '0' == clusterNum))
                    {
                        if (row == 0)
                            map[row][col] = '.';
                        else
                        {
                            char upperMineral = map[row - 1][col];
                            if (upperMineral - '0' == clusterNum || upperMineral == '.')
                                map[row][col] = upperMineral;
                        }
                    }
                }
            }
        }
    }
}