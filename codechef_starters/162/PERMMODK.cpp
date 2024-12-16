#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        if (n == 1 || k == 1 || (k == 2 && n % 2 == 1))
        {
            cout << "-1" << endl;
            continue;
        }

        if (n % 2 == 0)
        {
            for (int i = 0; i < n; i += 2)
            {
                cout << i + 2 << " " << i + 1 << " ";
            }
        }
        else
        {
            cout << "3 1 2" << " ";

            for (int i = 3; i < n; i += 2)
            {
                cout << i + 2 << " " << i + 1 << " ";
            }
        }

        cout << endl;
    }
}
