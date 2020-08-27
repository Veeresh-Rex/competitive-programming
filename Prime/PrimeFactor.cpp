/* Input:
2
100
35
Output:
2 5
5 7
*/

#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i, n) for (i = 0; i < n; i++)
#define Fo(i, k, n) for (i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define ll long long
#define pb insert
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;

void solve(int n)
{
    set<int> primeFacts;
    while (n % 2 == 0)
    {
        n /= 2;
        primeFacts.pb(2);
    }

    for (int i = 3; i * i <= n; i += 2)
    {
        while (n % i == 0)
        {
            n /= i;
            primeFacts.pb(i);
        }
    }
    for (auto i : primeFacts)
        cout << i << " ";
    cout << "\n";
}
int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        solve(n);
    }
    return 0;
}
