#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int count = 0;
    int size = n * 2 - 1;
    for (int i = 0; i <= size / 2; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (j < count)
            {
                cout << " ";
            }
            else if (j >= count && j < size - count)
            {
                cout << "*";
            }
        }
        cout << endl;
        count++;
    }
    count -= 2;
    for (int i = size / 2 + 1; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (j < count)
            {
                cout << " ";
            }
            else if (j >= count && j < size - count)
            {
                cout << "*";
            }
        }
        cout << endl;
        count--;
    }
    return 0;
}

/*
*********
 *******
  *****
   ***
    *
   ***
  *****
 *******
*********
*/