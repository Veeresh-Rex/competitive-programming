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
#define endll "\n"
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
bool state = 0;
void printNQueen(vvi sol)
{
    int i, j;
    int n = sol.size();

    fo(i, n)
    {

        fo(j, n)
        {
            if (sol[i][j])
                cout << "Q"
                     << " ";
            else
            {
                cout << "- ";
            }
        }
        cout << " \n";
    }
    cout << "\n";
}
bool isSafe(int i, int j, vvi sol)
{
    int n = sol.size(), k, l;
    for (k = 0; k < i; k++)
    {
        if (sol[k][j])
            return false;
    }
    for (k = i, l = j; k >= 0 && l >= 0; k--, l--)
    {
        if (sol[k][l])
            return false;
    }

    for (k = i, l = j; k >= 0 && l < n; k--, l++)
    {
        if (sol[k][l])
            return false;
    }
    return true;
}
bool nQueenSolve(int i, vvi &sol, int n)
{
    if (i >= n)
    {
        state = 1;
        printNQueen(sol);
        return true; // Make false to print all possible values
    }
    for (int j = 0; j < n; j++)
    {
        if (isSafe(i, j, sol))
        {
            sol[i][j] = 1;
            if (nQueenSolve(i + 1, sol, n))
                return true;
            //backtracking
            sol[i][j] = 0;
        }
    }
    return false;
}
void solve(int n)
{
    vvi sol(n, vi(n, 0));
    if (nQueenSolve(0, sol, n) == false && state == 0)
        cout << "No solution";
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
        state = 0;
        solve(n);
        cout << endll;
    }
}
