#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

// #1302번 베스트 셀러

int main()
{
    int n;
    map<string, int> um;

    cin >> n;
    string str;
    for (int i = 0; i < n; i++)
    {
        cin >> str;
        auto it = um.find(str);
        if (it == um.end())
        {
            um.insert(make_pair(str, 1));
        }
        else
        {
            um[str]++;
        }
    }

    int max_num = -1;
    for (auto &it : um)
    {
        if (it.second > max_num)
        {
            max_num = it.second;
        }
    }
    vector<string> vec;
    for (auto &it : um)
    {
        if (it.second == max_num)
        {
            vec.push_back(it.first);
        }
    }
    sort(vec.begin(), vec.end());

    cout << vec.front() << endl;

    return 0;
}