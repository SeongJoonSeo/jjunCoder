#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

typedef long long LL;
typedef pair<int, int> II;
#define X first
#define Y second

int main()
{
    ios_base::sync_with_stdio(false);
    int T, N, x, y;
    cin >> T;
    while (T--)
    {
        cin >> N;
        vector<II> pts;
        vector<int> choice(N, 0);
        for (int i = 0; i < N; i++)
        {
            cin >> x >> y;
            pts.push_back({x, y});
            if (i >= N / 2)
            {
                choice[i] = 1;
            }
        }
        LL min_sum = __LONG_LONG_MAX__;
        do
        {
            pair<LL, LL> vec_sum = {0, 0};
            for (int i = 0; i < N; i++)
            {
                // 시작점들의 좌표를 다 더한걸 끝점의 좌표 다 더한거에서 뺀다
                if (choice[i] == 1)
                {
                    vec_sum.X -= pts[i].X;
                    vec_sum.Y -= pts[i].Y;
                }
                else
                {
                    vec_sum.X += pts[i].X;
                    vec_sum.Y += pts[i].Y;
                }
            }
            LL tot_sum = vec_sum.X * vec_sum.X + vec_sum.Y * vec_sum.Y;
            min_sum = min(min_sum, tot_sum);
        } while (next_permutation(begin(choice), end(choice)));
        printf("%.6f\n", sqrt((double)min_sum));
    }
    return 0;
}