#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int dir[8][2] = {
    {-1, -1},
    {-1, 0},
    {-1, 1},
    {0, 1},
    {1, 1},
    {1, 0},
    {1, -1},
    {0, -1}};

bool isIn(int row, int col, int n)
{
    return (0 <= row && row < n && 0 <= col && col < n);
}

int game(vector<vector<int>> &board)
{
    const int n = board.size();
    int row = 0, col = 0;
    if (n == 1)
        return 0;
    while (!(row == 1 && col == 0))
    {
        if (row == 5)
        {
            int abc = 2;
        }
        const int item = board[row][col];

        if (item >= 0) // 8방향으로 지뢰 정보를 갖고 있다
        {
            if (item == 0)
            {
                for (int i = 0; i < 8; i++)
                {
                    int r = row + dir[i][0];
                    int c = col + dir[i][1];
                    if (isIn(r, c, n) && board[r][c] == -1)
                        board[r][c] = -3;
                }
            }
            else if (item == 3)
            {
                for (int i = 0; i < 8; i++)
                {
                    int r = row + dir[i][0];
                    int c = col + dir[i][1];
                    if (isIn(r, c, n))
                    {
                        int &target = board[r][c];
                        if (target < 0)
                            target = -2;
                    }
                }
            }
            else
            {
                vector<int> empty_holes;
                int empty_count = 0;
                int mine_count = 0;
                for (int i = 0; i < 8; i++)
                {
                    int r = row + dir[i][0];
                    int c = col + dir[i][1];
                    if (isIn(r, c, n))
                    {
                        const int target = board[r][c];
                        if (target < 0)
                        {
                            if (target == -1)
                            {
                                empty_count++;
                                empty_holes.push_back(i);
                            }
                            else if (target == -2)
                                mine_count++;
                        }
                    }
                    if (mine_count >= item)
                        break;
                }
                if (mine_count < item && empty_count <= item - mine_count)
                {
                    for (int i = 0; i < empty_holes.size(); i++)
                    {
                        int idx = empty_holes[i];
                        int r = row + dir[idx][0];
                        int c = col + dir[idx][1];
                        board[r][c] = -2;
                    }
                }
                else
                {
                    for (int i = 0; i < 8; i++)
                    {
                        int r = row + dir[i][0];
                        int c = col + dir[i][1];
                        if (isIn(r, c, n))
                        {
                            int &target = board[r][c];
                            if (target == -1)
                                target = -3;
                        }
                    }
                }
            }
        }

        if (row == 0 && col < n - 1)
        {
            col++;
            continue;
        }
        if (col == n - 1 && row < n - 1)
        {
            row++;
            continue;
        }
        if (row == n - 1 && col > 0)
        {
            col--;
            continue;
        }
        if (col == 0)
        {
            row--;
            continue;
        }
    }

    int ret = 0;
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            const int item = board[row][col];
            if (item == -2 || item == -1)
            {
                ret++;
            }
        }
    }
    return ret;
}

int main()
{
    int n;
    cin >> n;
    string inputstr;
    vector<vector<int>> board;
    board.assign(n, vector<int>(n, -1));
    // -1 : 닫힌칸
    // -2 : 지뢰가 있음
    // -3 : 지뢰가 없음
    for (int i = 0; i < n; i++)
    {
        cin >> inputstr;
        for (int j = 0; j < n; j++)
        {
            char c = inputstr[j];
            if (c == '#')
            {
                board[i][j] = -1;
            }
            else
            {
                board[i][j] = c - '0';
            }
        }
    }

    cout << game(board) << endl;
    return 0;
}