#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int main()
{
    int n;
    cin >> n;

    map<string, int> idxmap;
    map<string, string> m;
    map<string, bool> visit;
    vector<string> vec;

    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;

        idxmap[str] = i;

        visit[str] = false;
        vec.push_back(str);
        if (i != 0)
        {
            m.insert(make_pair(str, vec[i - 1]));
        }
        else
            m.insert(make_pair(str, "-1"));
    }

    int result = 0;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        visit[str] = true;

        string frontcar = m[str];
        if (idxmap[str] > i)
        {
            result++;
        }
        else
        {
            if (frontcar != "-1" && (!visit[frontcar]))
            {
                result++;
            }
        }
    }

    cout << result << endl;
    return 0;
}

/*
12345
54231

5
1
2
3
4
5
5
4
2
3
1
*/