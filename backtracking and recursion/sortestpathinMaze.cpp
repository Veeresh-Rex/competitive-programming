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
bool isSafe(vector<vector<bool>> maze, int i, int j, vector<vector<bool>> sol)
{
    int n = maze.size();
    int m = maze[0].size();
    return (i >= 0 && j >= 0 && i < n && j < m && maze[i][j] == 1 && (sol[i][j] == 0));
}
int sortestPath(vector<vector<bool>> &sol, vector<vector<bool>> maze, int i, int j)
{
    if (!isSafe(maze, i, j, sol))
    {
        return INT_MAX - 1;
    }
    if (i == 0 && j == 3) //Destination
    {
        return 0;
    }
    sol[i][j] = true;
    int right = sortestPath(sol, maze, i, j + 1);
    int top = sortestPath(sol, maze, i - 1, j);
    int left = sortestPath(sol, maze, i, j - 1);
    int down = sortestPath(sol, maze, i + 1, j);
    sol[i][j] = false;
    return min(min(right, top), min(left, down)) + 1;
}
void solve(vector<vector<bool>> maze, int n, int m)
{
    vector<vector<bool>> sol(n, vector<bool>(m, 0));
    int x = sortestPath(sol, maze, 0, 0);
    if (x == INT_MAX)
        cout << "No path found \n";
    else
    {
        cout << x << "\n";
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
        int n, m, k;
        cin >> n >> m;
        vector<vector<bool>> maze;
        for (int i = 0; i < n; i++)
        {
            vector<bool> line;
            for (int j = 0; j < m; j++)
            {
                cin >> k;
                line.pb(k);
            }
            maze.pb(line);
        }
        solve(maze, n, m);
    }
    return 0;
}
