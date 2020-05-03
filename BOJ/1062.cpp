#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

int answer = -1;
vector<bool> learned;
vector<string> words;
int alphaIndex[] = {0, 1, 0, 2, 3, 4, 5, 6, 0, 7, 8, 9, 10, 0, 11, 12, 13, 14, 15, 0, 16, 17, 18, 19, 20, 21};
// a b c d e f g h i j k l m  n o  p  q  r  s  t u  v  w  x  y  z
// 0 1 0 2 3 4 5 6 0 7 8 9 10 0 11 12 13 14 15 0 16 17 18 19 20 21

void learning(int startIdx, int wordCount)
{
    if (wordCount == 0)
    {
        int count = 0;
        for (int i = 0; i < words.size(); i++)
        {
            bool allLearned = true;
            for (int j = 0; j < words[i].length(); j++)
            {
                if (!learned[alphaIndex[words[i][j] - 'a']])
                {
                    allLearned = false;
                    break;
                }
            }
            if (allLearned)
                count++;
        }
        if (answer < count)
            answer = count;
        return;
    }

    for (int i = startIdx; i < 22; i++)
    {
        if (!learned[i])
        {
            learned[i] = true;
            learning(i + 1, wordCount - 1);
            learned[i] = false;
        }
    }
}

int main()
{
    int N, K;
    cin >> N >> K;

    learned.assign(22, false);
    learned[0] = true;
    //antic
    for (int i = 0; i < N; i++)
    {
        string inputstr;
        cin >> inputstr;
        //anta xxx tica
        inputstr = inputstr.substr(4, inputstr.length() - 8);
        string tempstr = "";
        for (int j = 0; j < inputstr.length(); j++)
        {
            char c = inputstr[j];
            if (c != 'a' && c != 'n' && c != 't' && c != 'i' && c != 'c')
                tempstr += inputstr[j];
        }
        words.push_back(tempstr);
    }
    if (K < 5)
    {
        cout << 0 << endl;
        return 0;
    }
    int startIdx = 1;
    int wordCount = K - 5;
    learning(startIdx, wordCount);
    cout << answer << endl;
    return 0;
}

/*
3 6
antarctica
antahellotica
antacartica

3 6
antaactica
antahellotica
antacartica
*/