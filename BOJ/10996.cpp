#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int upperSize = n % 2 == 0 ? n - 1 : n;
        for (int j = 0; j < upperSize; j++)
        {
            j % 2 == 0 ? cout << "*" : cout << " ";
        }
        cout << endl;
        int lowerSize = n % 2 == 0 ? n : n - 1;
        for (int j = 0; j < lowerSize; j++)
        {
            j % 2 == 0 ? cout << " " : cout << "*";
        }
        cout << endl;
    }

    return 0;
}
