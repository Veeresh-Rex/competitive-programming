/* Problem statement --> https://www.codechef.com/problems/KPRIME
*/

#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i, n) for (i = 0; i < n; i++)
#define Fo(i, k, n) for (i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define ll long long
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
#define mod 1000000007
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
void solve(vector<int> &total)
{
    for (int i = 2; i < total.size(); i++)
    {
        if (total[i] == 0)
        {
            for (int j = i; j < total.size(); j += i)
            {
                total[j]++;
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    vector<int> total(100006, 0);
    solve(total);
    while (t--)
    {
        int a, b, k, s = 0;
        cin >> a >> b >> k;
        for (int i = a; i <= b; i++)
        {
            if (total[i] == k)
                s++;
        }
        cout << s << "\n";
    }
    return 0;
}
