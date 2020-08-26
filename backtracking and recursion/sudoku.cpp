/*  

1
3 0 6 5 0 8 4 0 0
5 2 0 0 0 0 0 0 0
0 8 7 0 0 0 0 3 1
0 0 3 0 1 0 0 8 0
9 0 0 8 6 3 0 0 5
0 5 0 0 9 0 6 0 0
1 3 0 0 0 0 2 5 0
0 0 0 0 0 0 0 7 4
0 0 5 2 0 6 3 0 0

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
#define N 9
void ipgraph(int m);
void dfs(int u, int par);
void printGrid(vvi grid)
{
    for (int row = 0; row < N; row++)
    {
        for (int col = 0; col < N; col++)
            cout << grid[row][col] << " ";
        cout << endl;
    }
}
bool nextEmpty(vvi sudoku, int &i, int &j)
{
    for (int k = 0; k < 9; k++)
    {
        for (int l = 0; l < 9; l++)
        {
            if (sudoku[k][l] == 0)
            {
                i = k;
                j = l;
                return true;
            }
        }
    }
    return false;
}
bool UsedInRow(vvi grid, int row, int num)
{
    for (int col = 0; col < 9; col++)
        if (grid[row][col] == num)
            return true;
    return false;
}

bool UsedInCol(vvi grid, int col, int num)
{
    for (int row = 0; row < 9; row++)
        if (grid[row][col] == num)
            return true;
    return false;
}

bool UsedInBox(vvi grid, int boxStartRow,
               int boxStartCol, int num)
{
    for (int row = 0; row < 3; row++)
        for (int col = 0; col < 3; col++)
            if (grid[row + boxStartRow]
                    [col + boxStartCol] == num)
                return true;
    return false;
}
bool issafe(vvi grid, int row, int col, int num)
{
    return !UsedInRow(grid, row, num) && !UsedInCol(grid, col, num) && !UsedInBox(grid, row - row % 3, col - col % 3, num) && grid[row][col] == 0;
}
bool solve(vvi &sudoku)
{
    int i, j;
    if (!nextEmpty(sudoku, i, j))
        return true;
    for (int k = 1; k <= 9; k++)
    {
        if (issafe(sudoku, i, j, k))
        {
            sudoku[i][j] = k;
            if (solve(sudoku))
                return true;
            sudoku[i][j] = 0; //backtrack
        }
    }
    return false;
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
        vector<vi> sudoku;
        int i, j, n, x;

        fo(i, N)
        {
            vi temp;
            fo(j, N)
            {
                cin >> x;
                temp.pb(x);
            }
            sudoku.pb(temp);
        }

        if (solve(sudoku))
            printGrid(sudoku);  
        
        // else part if sudoku in not valid
        
    }
    return 0;
}
