#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        string a;
        cin >> a;
        int n = a.length();

        string ans = "";
        for (int i = n - 1; i >= 0; i--)
        {
            if (a[i] == 'q')
                ans.push_back('p');
            else if (a[i] == 'p')
                ans.push_back('q');
            else
                ans.push_back('w');
        }

        cout << ans << endl;
    }

    return 0;
}