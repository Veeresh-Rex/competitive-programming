#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i, n) for (i = 0; i < n; i++)
#define Fo(i, k, n) for (i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define ll long long
#define si(x) scanf("%d", &x)
#define sl(x) scanf("%lld", &x)
#define ss(s) scanf("%s", s)
#define pi(x) printf("%d\n", x)
#define pl(x) printf("%lld\n", x)
#define ps(s) printf("%s\n", s)
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
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
int mpow(int base, int exp);
void ipgraph(int m);
void dfs(int u, int par);
void printFlood(vvi flood)
{
    int m = flood[0].size();
    int n = flood.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << flood[i][j] << " ";
        }
        // cout << "\n";
    }
}
void solveFlood(vvi &flood, int i, int j, int n, int m, int k, int prev)
{
    if (i >= n || j >= m || i < 0 || j < 0)
    {
        return;
    }
    if (flood[i][j] == prev)
    {
        flood[i][j] = k;
    }
    else
    {
        return;
    }
    solveFlood(flood, i + 1, j, n, m, k, prev);
    solveFlood(flood, i, j - 1, n, m, k, prev);
    solveFlood(flood, i - 1, j, n, m, k, prev);
    solveFlood(flood, i, j + 1, n, m, k, prev);
}
void solve(vvi flood)
{
    int i, j;
    cin >> i >> j;
    int k;
    cin >> k;
    //  cout << "test" << i << " " << j << " " << k << "\n";
    int n = flood.size(), m = flood[0].size();
    int s = flood[i][j];
    solveFlood(flood, i, j, n, m, k, s);
    printFlood(flood);
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
        int n, m;
        cin >> n >> m;
        vector<vi> flood(n, vi(m));
        // int k;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> flood[i][j];
            }
        }
        solve(flood);

        cin.ignore();
    }
    return 0;
}
