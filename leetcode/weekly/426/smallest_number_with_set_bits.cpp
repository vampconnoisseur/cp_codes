#include <iostream>
using namespace std;

int findLastFromRight(int n)
{
    if (n == 0)
        return -1;

    int position = 0;
    while (n > 0)
    {
        n >>= 1;
        position++;
    }
    return position;
}

int smallestNumber(int n)
{
    int position = findLastFromRight(n);
    if (position == -1)
        return 0;
    return (1 << position) - 1;
}