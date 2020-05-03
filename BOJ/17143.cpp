#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <deque>
#include <map>

using namespace std;

vector<int> rowPos;
vector<int> colPos;
int R;
int C;

class Shark
{
public:
    int id;
    int row;
    int col;
    int speed;
    int dir;
    int size;
    Shark() {}
    Shark(int row, int col, int speed, int dir, int size, int id)
        : row(row), col(col), speed(speed), dir(dir), size(size), id(id)
    {
    }
    pair<int, int> move()
    {
        int next;
        int rSize = rowPos.size();
        int cSize = colPos.size();
        switch (dir)
        {
        case 1: //위
            next = (speed + rSize - row) % rSize;
            row = rowPos[next];
            if (next <= rSize / 2)
                dir = 2;
            break;

        case 2: //아래
            next = (speed + row) % rSize;
            row = rowPos[next];
            if (next > rSize / 2)
                dir = 1;
            break;

        case 3: //오른쪽
            next = (speed + col) % cSize;
            col = colPos[next];
            if (next > cSize / 2)
                dir = 4;
            break;

        case 4: //왼쪽
            next = (speed + cSize - col) % (cSize);
            col = colPos[next];
            if (next <= cSize / 2)
                dir = 3;
            break;

        default:
            break;
        }
        return make_pair(row, col);
    }
};

bool compare(Shark a, Shark b)
{
    return (a.size >= b.size);
}

int main()
{
    int M;
    cin >> R >> C >> M;

    for (int i = 0; i < R; i++)
        rowPos.push_back(i);
    for (int i = R - 2; i > 0; i--)
        rowPos.push_back(i);
    for (int i = 0; i < C; i++)
        colPos.push_back(i);
    for (int i = C - 2; i > 0; i--)
        colPos.push_back(i);

    deque<Shark> sharkMap[R][C];
    map<int, Shark> m;
    int sharkId = 0;

    for (int i = 0; i < M; i++)
    {
        int r, c, s, d, z;
        cin >> r >> c >> s >> d >> z;
        Shark shark = Shark(r - 1, c - 1, s, d, z, sharkId);
        sharkMap[r - 1][c - 1].push_back(shark);
        m.insert({sharkId, shark});
        sharkId++;
    }

    // 낚시왕이 잡은 상어 크기의 합
    int answer = 0;

    // 1. 낚시왕이 오른쪽으로 한 칸 이동한다.
    for (int col = 0; col < C; col++)
    {
        int min_row = R + 1;

        for (int row = 0; row < R; row++)
        {
            if (!sharkMap[row][col].empty())
            {
                min_row = row;
                break;
            }
        }

        // 2. 낚시왕이 있는 열에 있는 상어 중에서 땅과 제일 가까운 상어를 잡는다. 상어를 잡으면 격자판에서 잡은 상어가 사라진다.
        if (min_row != R + 1)
        {
            Shark s = sharkMap[min_row][col].front();
            answer += s.size;
            m.erase(s.id);
            sharkMap[min_row][col].clear();
        }

        // 3. 상어가 이동한다.
        for (auto it = m.begin(); it != m.end(); it++)
        {
            Shark s = it->second;
            sharkMap[s.row][s.col].pop_front();
            pair<int, int> newPos = s.move();
            sharkMap[newPos.first][newPos.second].push_back(s);
        }

        // 4. 이동했는데 같은 위치에 있으면 큰 놈이 다 잡아먹는다.
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                if (sharkMap[i][j].size() > 1)
                {
                    // sort(sharkMap[i][j].begin(), sharkMap[i][j].end(), compare);
                    for (auto &s : sharkMap[i][j])
                    {
                        cout << s.id << " ";
                        m.erase(s.id);
                    }
                    Shark shark = sharkMap[i][j].front();
                    sharkMap[i][j].clear();
                    sharkMap[i][j].push_back(shark);
                }
            }
            cout << endl;
        }
    }

    cout << answer << endl;
    return 0;
}