#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

// BOJ #1405 미친 로봇

double probs[4]; // 동서남북 순서
double totalP;
int dir[4][2] = {
    {-1, 0},
    {1, 0},
    {0, -1},
    {0, 1}};

double getProb(vector<int> &route)
{
    double ret = 1.0;
    for (int i = 0; i < route.size(); i++)
    {
        ret *= probs[route[i]];
    }
    return ret;
}

void DFS(vector<int> &route, int N, vector<vector<bool>> &visited, int x, int y)
{
    if (route.size() == N)
    {
        totalP += getProb(route);
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dir[i][0];
        int ny = y + dir[i][1];
        if (visited[nx][ny])
            continue;
        visited[nx][ny] = true;
        route.push_back(i);
        DFS(route, N, visited, nx, ny);
        route.pop_back();
        visited[nx][ny] = false;
    }
}

void driver(int N)
{
    vector<int> route;
    totalP = 0.0;

    vector<vector<bool>> visited;
    const int SIZE = 100;
    visited.assign(SIZE, vector<bool>(SIZE, false));
    int x = 50, y = 50;
    visited[x][y] = true;
    DFS(route, N, visited, x, y);
}

int main()
{
    // input 받기
    int N;
    cin >> N;

    for (int i = 0; i < 4; i++)
    {
        int p;
        cin >> p;
        probs[i] = (double)p / (double)100;
    }
    driver(N);

    cout.precision(9);
    cout << totalP << endl;
    return 0;
}