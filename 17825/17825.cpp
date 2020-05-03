#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int maxScoreSum = -1;

class Node
{
public:
    int idx;
    int score;
    int nextNodeIdx;
    int horseNum;
    bool blue;
    Node(int idx, int score, int nextNodeIdx, bool blue = false, int horseNum = -1)
        : idx(idx), score(score), nextNodeIdx(nextNodeIdx), blue(blue), horseNum(horseNum)
    {
    }
    int nextNode(bool start, bool last, int horseNum);
};

// 시작(0) + 31 + 도착(32)
Node board[33] = {
    Node(0, 0, 1),
    Node(1, 2, 2),
    Node(2, 4, 3),
    Node(3, 6, 4),
    Node(4, 8, 5),
    Node(5, 10, 21, true),
    Node(6, 12, 7),
    Node(7, 14, 8),
    Node(8, 16, 9),
    Node(9, 18, 10),
    Node(10, 20, 25, true),
    Node(11, 22, 12),
    Node(12, 24, 13),
    Node(13, 26, 14),
    Node(14, 28, 15),
    Node(15, 30, 27, true),
    Node(16, 32, 17),
    Node(17, 34, 18),
    Node(18, 36, 19),
    Node(19, 38, 20),
    Node(20, 40, 32),
    Node(21, 13, 22),
    Node(22, 16, 23),
    Node(23, 19, 24),
    Node(24, 25, 30),
    Node(25, 22, 26),
    Node(26, 24, 24),
    Node(27, 28, 28),
    Node(28, 27, 29),
    Node(29, 26, 24),
    Node(30, 30, 31),
    Node(31, 35, 20),
    Node(32, 0, 32)};

int Node::nextNode(bool start, bool last, int horseNum)
{
    int ret = -1;
    if (start)
    {
        this->horseNum = -1;
    }
    if (blue)
    {
        if (start)
            ret = nextNodeIdx;
        else
            ret = idx + 1;
    }
    else
        ret = nextNodeIdx;

    if (last)
    {
        if (nextNodeIdx != 32 && board[nextNodeIdx].horseNum != -1)
            ret = -1;
        else
            board[nextNodeIdx].horseNum = horseNum;
    }
    return ret;
}

void traverse(vector<int> &cases, int *diceNum)
{
    int horseCurIdx[4] = {0, 0, 0, 0};
    int scoreSum = 0;
    for (int i = 0; i < cases.size(); i++)
    {
        int moveNum = diceNum[i];
        int horseNum = cases[i];

        for (int j = 0; j < moveNum; j++)
        {
            int curIdx = horseCurIdx[horseNum];
            bool start = false;
            bool last = false;
            if (j == 0)
                start = true;
            if (j == moveNum - 1)
                last = true;
            int nextIdx = board[curIdx].nextNode(start, last, horseNum);
            // if (nextIdx == 32)
            //     break;
            if (nextIdx == -1)
                return;
            horseCurIdx[horseNum] = nextIdx;
            if (last)
                scoreSum += board[nextIdx].score;
        }
    }
    maxScoreSum = max(maxScoreSum, scoreSum);
}

void bf(vector<int> &cases, int *diceNum)
{
    if (cases.size() == 10)
    {
        // base case
        traverse(cases, diceNum);
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        cases.push_back(i);
        bf(cases, diceNum);
        cases.pop_back();
    }
}

int main()
{
    int n;
    int diceNum[10];
    for (int i = 0; i < 10; i++)
    {
        cin >> n;
        diceNum[i] = n;
    }

    vector<int> cases;
    bf(cases, diceNum);
    cout << maxScoreSum << endl;
    return 0;
}