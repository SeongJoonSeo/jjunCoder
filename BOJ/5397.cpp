#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
    int tc;
    cin >> tc;
    for (int t = 0; t < tc; t++)
    {
        string inputStr;
        cin >> inputStr;
        stack<char> result;
        stack<char> backup;
        for (int i = 0; i < inputStr.length(); i++)
        {
            char c = inputStr[i];
            char temp;
            if (c == '<')
            {
                if (!result.empty())
                {
                    temp = result.top();
                    backup.push(temp);
                    result.pop();
                }
            }
            else if (c == '>')
            {
                if (!backup.empty())
                {
                    temp = backup.top();
                    result.push(temp);
                    backup.pop();
                }
            }
            else if (c == '-')
            {
                if (!result.empty())
                {
                    result.pop();
                }
            }
            else
            {
                result.push(c);
            }
        }
        while (!backup.empty())
        {
            char temp;
            temp = backup.top();
            result.push(temp);
            backup.pop();
        }
        string resultStr = "";
        while (!result.empty())
        {
            char temp;
            temp = result.top();
            result.pop();
            resultStr += temp;
        }
        for (int i = resultStr.length() - 1; i >= 0; i--)
        {
            cout << resultStr[i];
        }
        cout << endl;
    }
    return 0;
}
