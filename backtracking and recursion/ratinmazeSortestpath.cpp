#include <bits/stdc++.h>
using namespace std;
#define ll long long
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

bool isSafe(vvi maze, int i, int j, vvi sol)
{
    int n = maze.size();
    int m = maze[0].size();
    if (i >= 0 && i < n && j >= 0 && j < m && (maze[i][j] == 1) && (sol[i][j] == 0))
    {
        return true;
    }
    return false;
}
void printSol(vvi maze)
{
    int n = maze.size();
    int m = maze[0].size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << maze[i][j] << " ";
        }
        cout << "\n";
    }
}
void sortestpath(vvi maze, int i, int j, vvi &sol, int &mini, int dist, vvi &solution)
{

    if (i == 6 && j == 6)
    {
        sol[i][j] = 1;
        //  printSol(sol);
        mini = min(mini, dist);
        solution = sol;
        // cout << mini << "\n";
        sol[i][j] = 0;
        return;
    }
    sol[i][j] = true;
    if (isSafe(maze, i + 1, j, sol))
        sortestpath(maze, i + 1, j, sol, mini, dist + 1, solution);
    if (isSafe(maze, i - 1, j, sol))
        sortestpath(maze, i - 1, j, sol, mini, dist + 1, solution);
    if (isSafe(maze, i, j + 1, sol))
        sortestpath(maze, i, j + 1, sol, mini, dist + 1, solution);
    if (isSafe(maze, i, j - 1, sol))
        sortestpath(maze, i, j - 1, sol, mini, dist + 1, solution);
    sol[i][j] = false;
}
void solve(vvi maze)
{
    int n = maze.size();
    int m = maze[0].size();
    vvi sol(n, vi(m, 0));
    int mindist = INT_MAX;
    vvi solution(n, vi(m));

    sortestpath(maze, 0, 0, sol, mindist, 0, solution);

    if (mindist == INT_MAX)
        cout << "No solution";
    else
    {
        cout << "Minimum distance: " << mindist << "\n";
        printSol(solution);
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
        int n, m;
        cin >> n >> m;
        vvi maze(n, vi(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> maze[i][j];
            }
        }
        solve(maze);
    }
    return 0;
}
