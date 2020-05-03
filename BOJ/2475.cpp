#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> vec;
    int n;
    for (int i = 0; i < 5; i++)
    {
        cin >> n;
        vec.push_back(n);
    }
    int sum = 0;
    for (auto &num : vec)
    {
        sum += num * num;
    }
    cout << sum % 10 << endl;
    return 0;
}