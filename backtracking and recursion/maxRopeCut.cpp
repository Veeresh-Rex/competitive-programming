#include <bits/stdc++.h>
using namespace std;]
typedef vector<vl> vvl;
int mpow(int base, int exp);
void ipgraph(int m);
void dfs(int u, int par);

int maxCut(int n, int a, int b, int c)
{
    if (n == 0)
    {
        return 0;
    }
    if (n < 0)
        return -1;
    int res = max(max(maxCut(n - a, a, b, c), maxCut(n - b, a, b, c)), maxCut(n - c, a, b, c));
    if (res == -1)
        return -1;
    else
    {
        return res + 1;
    }
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
        int len;
        cin >> len;
        int a, b, c;
        cin >> a >> b >> c;
        cout << "max cut " << maxCut(len, a, b, c) << "\n";
    }
    return 0;
}
