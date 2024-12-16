#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        int a[n - 1];

        for (int i = 0; i < n - 1; i++)
        {
            cin >> a[i];
        }

        sort(a, a + n - 1);

        int idx = 1;
        int num = 1;
        cout << num << " ";

        for (int i = 0; i < n - 1; i++)
        {
            cout << a[i] - num << " ";
            num = a[i] - num;
        }

        cout << endl;
    }

    return 0;
}