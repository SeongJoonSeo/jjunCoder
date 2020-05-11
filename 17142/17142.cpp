#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N, M;
int trycount = 0;
const int FAIL = 987654321;
int min_time = FAIL;
int hole_count = 0, hole_backup = 0;
const int dir[4][2] = {
    {-1, 0},
    {1, 0},
    {0, -1},
    {0, 1}};

//<--backup, restore data
vector<vector<int>> board, backup;
vector<vector<string>> visit, visit_backup;
//backup, restore data-->

vector<pair<int, int>> start_points, activates;

void restore();
void setting();
void solve();
int bfs();
void activate(int start);
void printVisit();
string itos(int i) { return to_string(i); }
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
    int item;
    board.assign(N, vector<int>(N, -1));
    visit.assign(N, vector<string>(N, "+"));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            cin >> item;
            board[i][j] = item;
            if (item == 2)
                start_points.push_back(make_pair(i, j));
        }

    hole_count = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            if (board[i][j] == 1)
            {
                visit[i][j] = "-";
            }
            else if (board[i][j] == 2)
            {
                visit[i][j] = "*";
            }
            else
            {
                hole_count++;
                visit[i][j] = "+";
            }
        }

    hole_backup = hole_count;
    visit_backup = vector<vector<string>>(visit.begin(), visit.end());
    backup = vector<vector<int>>(board.begin(), board.end());
}

void solve()
{
    // <== Debug
    // restore();
    // for (int i = 0; i < 3; i++)
    //     activates.push_back(start_points[i]);
    // cout << bfs() << endl;
    // Debug ==>
    restore();
    if (hole_count == 0)
    {
        cout << 0 << endl;
        return;
    }
    activate(0);
    if (min_time == FAIL)
        min_time = -1;
    cout << min_time << endl;
}
void activate(int start)
{
    if (activates.size() == M)
    {
        //새로운 활성 바이러스 시작 위치로 시뮬레이션
        restore();
        int time = bfs();
        if (hole_count <= 0)
            min_time = min(min_time, time);
        return;
        // 시물레이션 끝나고 바이러스가 퍼지는 최소 시간 저장
    }
    else
    {
        for (int i = start; i < start_points.size(); i++)
        {
            activates.push_back(start_points[i]);
            activate(start + 1);
            activates.pop_back();
        }
    }
}

int bfs()
{
    queue<int> rowq, colq;
    int time = 0;

    for (int i = 0; i < activates.size(); i++)
    {
        int row = activates[i].first;
        int col = activates[i].second;
        rowq.push(row);
        colq.push(col);
        visit[row][col] = itos(time);
    }
    // printVisit();

    while (!rowq.empty())
    {
        int row = rowq.front();
        int col = colq.front();
        if (stoi(visit[row][col]) != time)
        {
            // printVisit();
            time++;
            if (hole_count == 0)
                return time;
        }
        rowq.pop();
        colq.pop();

        for (int i = 0; i < 4; i++)
        {
            int nrow = row + dir[i][0];
            int ncol = col + dir[i][1];
            if (isIn(nrow, ncol) && board[nrow][ncol] != '-' && (visit[nrow][ncol] == "+" || (visit[nrow][ncol] == "*")))
            {
                if (visit[nrow][ncol] == "+")
                    hole_count--;
                visit[nrow][ncol] = itos(time + 1);
                rowq.push(nrow);
                colq.push(ncol);
            }
        }
    }
    return time;
}

void restore()
{
    board = vector<vector<int>>(backup.begin(), backup.end());
    hole_count = hole_backup;
    visit = vector<vector<string>>(visit_backup.begin(), visit_backup.end());
}

void printVisit()
{
    cout << "Try #" << trycount++ << endl;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << visit[i][j] << " ";
        }
        cout << endl;
    }
    cout << "============================" << endl;
}