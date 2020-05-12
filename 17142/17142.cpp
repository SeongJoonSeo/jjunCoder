#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stdint.h>

using namespace std;

typedef pair<int, int> ii;

int N, M;
int hole_count = 0, hole_backup = 0;
const int dir[4][2] = {
    {-1, 0},
    {1, 0},
    {0, -1},
    {0, 1}};

vector<vector<int>> board, visit;
vector<ii> start_points;

void setting();
void solve();
void activate();
int bfs(queue<ii> &q);
bool isIn(int r, int c) { return 0 <= r && r < N && 0 <= c && c < N; }

int main()
{
    setting();
    solve();
    return 0;
}

void setting()
{
    cin >> N >> M;
    board.assign(N, vector<int>(N, -1));
    hole_count = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 2)
                start_points.push_back({i, j});
            else if (board[i][j] == 0)
                hole_count++;
        }
    hole_backup = hole_count;
}

void solve()
{
    if (hole_count == 0)
    {
        cout << 0 << endl;
        return;
    }
    activate();
}
void activate()
{
    vector<int> choice(start_points.size(), 0);
    int min_time = INT32_MAX;

    for (int i = 0; i < M; i++)
        choice[i] = 1;
    do
    {
        queue<ii> activated_virus;
        visit.assign(N, vector<int>(N, 0));
        hole_count = hole_backup;
        for (int i = 0; i < start_points.size(); i++)
            if (choice[i] == 1)
            {
                activated_virus.push(start_points[i]);
                visit[start_points[i].first][start_points[i].second] = 1;
            }
        min_time = min(min_time, bfs(activated_virus));
    } while (prev_permutation(choice.begin(), choice.end()));

    if (min_time == INT32_MAX)
        min_time = -1;
    cout << min_time << endl;
}

int bfs(queue<ii> &q)
{
    int time = 0;

    while (!q.empty())
    {
        int qs = q.size();
        while (qs--)
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            if (board[row][col] == 0)
                hole_count--;
            if (hole_count == 0)
                return time;
            for (int i = 0; i < 4; i++)
            {
                int nrow = row + dir[i][0];
                int ncol = col + dir[i][1];
                if (isIn(nrow, ncol) && board[nrow][ncol] != 1 && visit[nrow][ncol] == 0)
                {

                    q.push({nrow, ncol});
                    visit[nrow][ncol] = 1;
                }
            }
        }
        ++time;
    }
    return INT32_MAX;
}
