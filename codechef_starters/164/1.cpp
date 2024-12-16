#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, k, p;

        cin >> n >> k >> p;

        priority_queue<int> q;

        for (size_t i = 0; i < n; i++)
        {
            int ele;
            cin >> ele;

            q.push(ele);
        }

        int vedH = q.top() + k;
        q.pop();
        int varH = p;

        while (!q.empty())
        {
            varH += q.top();
            q.pop();
        }

        if (varH > vedH)
            cout << "Varun" << endl;
        else if (varH == vedH)
            cout << "Equal" << endl;
        else
            cout << "Ved" << endl;
    }

    return 0;
}