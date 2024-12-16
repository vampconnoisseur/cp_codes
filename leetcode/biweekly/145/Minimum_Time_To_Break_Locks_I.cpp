#include <iostream>
#include <algorithm>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> p3;
typedef pair<ll, ll> pl;
typedef pair<int, pl> p3l;
typedef pair<double, double> pdd;
typedef vector<int> vi;
typedef vector<ld> vd;

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)
#define SORT(v) sort((v).begin(), (v).end())
#define UN(v) SORT(v), (v).erase(unique((v).begin(), (v).end()), (v).end())
#define CL(a, b) memset(a, b, sizeof a)
#define pb push_back

class Solution
{
public:
    int findMinimumTime(vector<int> &a, int K)
    {
        int res = 1e9;
        SORT(a);
        do
        {
            int x = 1;
            int r = 0;
            REP(i, a.size())
            {
                r += ceil((double)a[i] / (double)x);
                cout << r << "----" << a[i] << ";  ";
                x += K;
            }
            cout << endl;
            res = min(res, r);

        } while (next_permutation(a.begin(), a.end()));
        return res;
    }
};

int main()
{
    vector<int> strength1 = {3, 4, 1};
    int K1 = 3;
    Solution sol1;
    int result1 = sol1.findMinimumTime(strength1, K1);
    cout << "Test Case 1: Minimum Time = " << result1 << endl;
    return 0;
}