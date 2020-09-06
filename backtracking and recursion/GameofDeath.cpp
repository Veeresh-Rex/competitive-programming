/*
Input:
3
2 1
4 2
50 10
Output:
2
1
36
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) x.begin(), x.end()
#define sortall(x) sort(all(x))
int jos(int n, int k)
{
    if (n == 1)
        return n;
    // cout << jos(n - 1, k) + k - 1 << "\n";
    return (jos(n - 1, k) + k - 1) % n + 1;
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
        int k;
        cin >> k;
        cout << jos(n, k) << "\n";
    }
    return 0;
}
