// BOJ 1194번: 달이 차오른다 가자
#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

typedef pair<int, int> II;
#define X first
#define Y second

int n, m, sr, sc;
vector<vector<bool>> visited[65];
vector<vector<char>> board;
// r,c 를 방문 했는지, 어떤 키를 가지고 방문 했는지 정보를 나타낸다

void setting();
void solution();

int main() {
    setting();
    solution();
    return 0;
}

void setting() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    board.assign(n, vector<char>(m));
    for (int i = 0; i < 65; i++)
        visited[i].assign(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            if (board[i][j] == '0') {
                sr = i;
                sc = j;
                board[i][j] = '.';
            }
        }
}

int getKey(int key, int keyNum) {
    int ret = key | (1 << keyNum);
    return ret;
}

bool hasKey(int key, int keyNum) {
    int ret = key & (1 << keyNum);
    return ret;
}

int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool isIn(int r, int c) {
    return 0 <= r && r < n && 0 <= c && c < m;
}

// key : a,b,c,d,e,f 6개
// bit : 111111 6bit 필요
void solution() {
    // row, col, move, key
    queue<pair<II, II>> q;
    q.push({{sr, sc}, {0, 0}});
    visited[0][sr][sc] = true;

    while (!q.empty()) {
        II pos = q.front().first;
        II info = q.front().second;
        q.pop();
        int move = info.first;
        int key = info.second;

        for (int i = 0; i < 4; i++) {
            int nr = pos.X + dir[i][0];
            int nc = pos.Y + dir[i][1];
            if (!isIn(nr, nc) || visited[key][nr][nc] || board[nr][nc] == '#')
                continue;
            char boardItem = board[nr][nc];
            if ('a' <= boardItem && boardItem <= 'f') {
                int nextKey = getKey(key, boardItem - 'a');
                visited[nextKey][nr][nc] = true;
                q.push({{nr, nc}, {move + 1, nextKey}});
            } else if (('A' <= boardItem && boardItem <= 'F' && hasKey(key, boardItem - 'A')) || boardItem == '.') {
                visited[key][nr][nc] = true;
                q.push({{nr, nc}, {move + 1, key}});
            } else if (boardItem == '1') {
                cout << move + 1 << endl;
                return;
            }
        }
    }

    cout << -1 << endl;
    return;
}