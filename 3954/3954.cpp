#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

int loopIdx[4097];

void setting(string op);

int main()
{
    ios_base::sync_with_stdio(false);
    int tc, Sm, Sc, Si;

    cin >> tc;
    while (tc--)
    {
        string op, inputStr;
        cin >> Sm >> Sc >> Si;
        cin >> op >> inputStr;
        vector<int> memory(Sm, 0);
        fill(begin(loopIdx), end(loopIdx), 0);
        setting(op);
        bool success = false;
        int op_idx = 0, max_op_idx = 0, ptr = 0, input_ptr = 0;
        for (int i = 0; i < 50000000; i++)
        {
            if (op_idx >= Sc)
            {
                cout << "Terminates" << endl;
                success = true;
                break;
            }

            if (op[op_idx] == '+')
            {
                memory[ptr] = (memory[ptr] + 1) % 256;
            }
            else if (op[op_idx] == '-')
            {
                memory[ptr] = memory[ptr] - 1 < 0 ? 255 : memory[ptr] - 1;
            }
            else if (op[op_idx] == '>')
            {
                ptr = (ptr + 1) % Sm;
            }
            else if (op[op_idx] == '<')
            {
                ptr = ptr - 1 < 0 ? Sm - 1 : ptr - 1;
            }
            else if (op[op_idx] == '[')
            {
                if (memory[ptr] == 0)
                    op_idx = loopIdx[op_idx];
            }
            else if (op[op_idx] == ']')
            {
                if (memory[ptr] != 0)
                    op_idx = loopIdx[op_idx];
            }
            else if (op[op_idx] == ',')
            {
                memory[ptr] = input_ptr >= Si ? 255 : (int)inputStr[input_ptr];
                input_ptr = input_ptr >= Si ? input_ptr : input_ptr + 1;
            }
            op_idx++;
            max_op_idx = max(max_op_idx, op_idx);
        }
        if (!success)
        {
            cout << "Loops " << loopIdx[max_op_idx] << " " << max_op_idx << endl;
        }
    }
    return 0;
}

void setting(string op)
{
    stack<int> s;
    for (int i = 0; i < op.length(); i++)
    {
        char c = op[i];
        if (c == '[')
        {
            s.push(i);
        }
        else if (c == ']')
        {
            int right = i;
            int left = s.top();
            s.pop();
            loopIdx[right] = left;
            loopIdx[left] = right;
        }
    }
}