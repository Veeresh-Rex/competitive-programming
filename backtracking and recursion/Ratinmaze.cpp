/*  

For test

1
6
1 1 1 0 0 0
0 1 1 0 1 0
1 1 1 0 0 0
0 0 1 1 0 0
0 0 1 1 0 0
1 0 0 1 1 1




Prints all possible paths.


*/

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
//bool solveMaze(vector<vi>, int x, int y, vector<vi>);
bool isSafe(vector<vi> maze, int x, int y)
{

    if (x >= 0 && x < maze.size() && y >= 0 && y < maze.size() && maze[x][y] == 1)
        return true;
    else
    {
        return false;
    }
}
void printSol(vector<vi> sol)
{
    //   cout << "test2";
    for (int i = 0; i < sol.size(); i++)
    {
        for (int j = 0; j < sol.size(); j++)
            cout << sol[i][j] << " ";
        cout << endl;
    }
    cout << "\n";
}
bool solveMaze(vector<vi> maze, int x, int y, vector<vi> &sol)
{
    // cout << "test3" << endl
    if (x == maze.size() - 1 && y == maze.size() - 1)
    {
        sol[x][y] = 1;
        printSol(sol);
        return false;  //make true for one path
    }
    if (isSafe(maze, x, y))
    {
        sol[x][y] = 1;
        if (solveMaze(maze, x + 1, y, sol))
            return true;
        if (solveMaze(maze, x, y + 1, sol))
            return true;
        else
        {
            sol[x][y] = 0;
            return false;
        }
    }
    return false;
}
void solve(vector<vi> maze)
{
    int n = maze.size();
    vector<vi> sol(n, vi(n, 0));
    if (solveMaze(maze, 0, 0, sol) == false)
    {
        //  cout << "No solution";
        if (!sol[n - 1][n - 1])
        {
            cout << "No solution";
        }
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

        vector<vi> maze;
        int i, j, n, x;
        cin >> n;
        fo(i, n)
        {
            vi temp;
            fo(j, n)
            {
                cin >> x;
                temp.pb(x);
            }
            maze.pb(temp);
        }

        solve(maze);
    }
}



