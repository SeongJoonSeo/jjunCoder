#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

// 2819 상근이의 로봇

// const vars
const string direction = "SJIZ"; // 북,남,동,서
const int dirx[4] = {0, 0, 1, -1};
const int diry[4] = {1, -1, 0, 0};

// function list
void precalc(vector<int> &x_vec, vector<int> &y_vec, vector<long long> &x_psum, vector<long long> &y_psum);
int lower_bound(int robot_position, const vector<int> &vec);
long long summing(int robot_position, int lower_bound_idx, const vector<long long> &psum);

int main()
{
    // Input
    int n, m, x, y;
    scanf("%d %d", &n, &m);
    vector<int> xvec, yvec;

    // 업데이트 되는 변수
    vector<long long> parital_sum_x;
    vector<long long> parital_sum_y;

    string command;
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &x, &y);
        xvec.push_back(x);
        yvec.push_back(y);
    }

    // precalculation
    precalc(xvec, yvec, parital_sum_x, parital_sum_y);

    // main process
    int curx = 0, cury = 0;
    cin >> command;
    for (int i = 0; i < m; i++)
    {
        char dir = command[i];
        for (int j = 0; j < 4; j++)
        {
            if (dir == direction[j])
            {
                curx += dirx[j];
                cury += diry[j];
                int lbx = lower_bound(curx, xvec);
                int lby = lower_bound(cury, yvec);
                long long distx = summing(curx, lbx, parital_sum_x);
                long long disty = summing(cury, lby, parital_sum_y);
                printf("%lld\n", distx + disty);
            }
        }
    }

    return 0;
}

void precalc(vector<int> &x_vec, vector<int> &y_vec, vector<long long> &x_psum, vector<long long> &y_psum)
{
    sort(x_vec.begin(), x_vec.end());
    sort(y_vec.begin(), y_vec.end());

    long long sum = 0;
    for (int i = 0; i < x_vec.size(); i++)
    {
        sum += x_vec[i];
        x_psum.push_back(sum);
    }
    sum = 0;
    for (int i = 0; i < y_vec.size(); i++)
    {
        sum += y_vec[i];
        y_psum.push_back(sum);
    }
}

int lower_bound(int robot_position, const vector<int> &vec)
{
    int left = 0;
    int right = vec.size();
    int mid = (left + right) / 2;
    int lower_bound_idx = right;
    while (left <= right)
    {
        if (vec[mid] >= robot_position)
        {
            lower_bound_idx = min(lower_bound_idx, mid);
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
        mid = (left + right) / 2;
    }
    return lower_bound_idx;
}

long long summing(int robot_position, int lower_bound_idx, const vector<long long> &psum)
{
    long long left_psum, right_psum;
    long long total_sum = psum.back();
    int n = psum.size();
    if (lower_bound_idx == 0)
        return total_sum - n * robot_position;
    else if (lower_bound_idx == n)
        return n * robot_position - total_sum;
    else
    {
        int leftn = lower_bound_idx;
        int rightn = n - leftn;
        left_psum = psum[lower_bound_idx - 1];
        right_psum = total_sum - left_psum;
        return (leftn * robot_position - left_psum + right_psum - rightn * robot_position);
    }
}
