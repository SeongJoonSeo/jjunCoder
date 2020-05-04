#include <iostream>
#include <string>
#include <vector>

using namespace std;

// # 1541 잃어버린 괄호

int main()
{
    string inputstr;
    cin >> inputstr;
    vector<int> vec;
    int num = 0;
    string numstr = "";
    int sum = 0;
    for (int i = 0; i < inputstr.length(); i++)
    {
        char c = inputstr[i];
        if (c == '-')
        {
            num = stoi(numstr);
            numstr = "";
            num += sum;
            sum = 0;
            vec.push_back(num);
        }
        else if (c == '+')
        {
            sum += stoi(numstr);
            numstr = "";
        }
        else
        {
            numstr += c;
        }
    }
    num = stoi(numstr);
    numstr = "";
    num += sum;
    sum = 0;
    vec.push_back(num);
    int result = vec.front();
    for (int i = 1; i < vec.size(); i++)
    {
        result -= vec[i];
    }
    cout << result << endl;
    return 0;
}