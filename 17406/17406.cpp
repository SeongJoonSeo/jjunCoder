#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

vector<vector<int>> A;
vector<int> rvec, cvec, svec;
vector<int> ops;
int row_size, col_size, k;

void setting();
void permutation();
void rotation(int op_num);
int get_value();
void print();

int main()
{
    cin >> row_size >> col_size >> k;
    setting();
    permutation();
    return 0;
}

void setting()
{
    A.assign(row_size, vector<int>(col_size, -1));

    rvec.assign(k, 0);
    cvec.assign(k, 0);
    svec.assign(k, 0);

    int num;
    int r, c, s;
    for (int row = 0; row < row_size; row++)
    {
        for (int col = 0; col < col_size; col++)
        {
            cin >> num;
            A[row][col] = num;
        }
    }
    for (int i = 0; i < k; i++)
    {
        cin >> r >> c >> s;
        rvec[i] = r;
        cvec[i] = c;
        svec[i] = s;
        ops.push_back(i);
    }
}

void permutation()
{
    vector<vector<int>> B;
    B.assign(A.begin(), A.end());
    int min_value = 987654321;
    do
    {
        for (int i = 0; i < k; i++)
            rotation(ops[i]);
        int array_value = get_value();
        if (min_value > array_value)
            min_value = array_value;
        A.assign(B.begin(), B.end());
    } while (next_permutation(ops.begin(), ops.end()));
    cout << min_value << endl;
}

void rotation(int op_num)
{
    int r = rvec[op_num] - 1;
    int c = cvec[op_num] - 1;
    int s = svec[op_num];

    for (int count = 1; count <= s; count++)
    {
        int backup = A[r - count][c - count];

        for (int row = r - count; row < r + count; row++)
        {
            int col = c - count;
            A[row][col] = A[row + 1][col];
        }

        for (int col = c - count; col < c + count; col++)
        {
            int row = r + count;
            A[row][col] = A[row][col + 1];
        }

        for (int row = r + count; row > r - count; row--)
        {
            int col = c + count;
            A[row][col] = A[row - 1][col];
        }

        for (int col = c + count; col > c - count; col--)
        {
            int row = r - count;
            A[row][col] = A[row][col - 1];
        }
        A[r - count][c - count + 1] = backup;
    }
}

int get_value()
{
    int min_value = 987654321;
    for (int row = 0; row < row_size; row++)
    {
        int row_sum = 0;
        for (int col = 0; col < col_size; col++)
        {
            row_sum += A[row][col];
        }
        if (min_value > row_sum)
            min_value = row_sum;
    }
    return min_value;
}

void print()
{
    for (int i = 0; i < row_size; i++)
    {
        for (int j = 0; j < col_size; j++)
        {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
    cout << "----------" << endl;
}