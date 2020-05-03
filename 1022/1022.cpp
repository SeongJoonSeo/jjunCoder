#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

// BOJ #1022 소용돌이 예쁘게 출력하기

int get_num(const int row, const int col)
{
    int num = 0;
    int level = max(abs(row), abs(col));
    int start_num = (2 * level - 1) * (2 * level - 1) + 1;
    int count = 2 * level;
    if (col == level && row != level)
    {
        num = -row + level - 1 + start_num;
    }
    else if (row == -level)
    {
        num = -col + level - 1 + start_num + count;
    }
    else if (col == -level)
    {
        num = row + level - 1 + start_num + count * 2;
    }
    else if (row == level)
    {
        num = col + level - 1 + start_num + count * 3;
    }
    return num;
}

int main()
{
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    int long_len = (int)log10(get_num(r2, c2)) + 1;
    long_len = max(long_len, (int)log10(get_num(r1, c1)) + 1);
    long_len = max(long_len, (int)log10(get_num(r1, c2)) + 1);
    long_len = max(long_len, (int)log10(get_num(r2, c1)) + 1);

    for (int i = 0; i <= r2 - r1; i++)
    {
        int row = r1 + i;
        for (int j = 0; j <= c2 - c1; j++)
        {
            int col = c1 + j;
            int num = get_num(row, col);
            int num_len = (int)log10(num) + 1;
            for (int k = 0; k < long_len - num_len; k++)
                printf(" ");
            printf("%d", num);
            if (j != c2 - c1)
                printf(" ");
        }
        cout << endl;
    }

    return 0;
}
