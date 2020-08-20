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
void solve(string s)
{
    int n = s.size();
    bool arr[n][n];
    clr(arr);
    int start = 0, maxLen = 1;
    bool f = 1;
    for (int i = 0; i < n - 1; i++)   // if lenght of string is less than 2
    {
        arr[i][i] = 1;
        if (s[i] == s[i + 1])
        {
            arr[i][i + 1] = 1;
            if (f == 1)
                start = i;
            maxLen = 2;
            f = 0;
        }
    }
    arr[n - 1][n - 1] = true;
    // if lenght of string is greater than 3
    for (int i = 3; i <= n; i++)
    {

        for (int l = 0; l < n - i + 1; l++)
        {
            int j = i + l - 1;
            if (s[l] == s[j])
            {
                arr[l][j] = 1;
                if (arr[l + 1][j - 1])
                {
                    if (i > maxLen)
                    {
                        if (i != maxLen)
                            maxLen = i;
                        start = l;
                        maxLen = i;
                    }
                }
                else
                {
                    arr[l][j] = 0;
                }
            }
        }
    }
    for (int g = start; g <= start + maxLen - 1; g++)
        cout << s[g];
    cout << "\n";
    //  cout << start << " " << maxLen << "\n";

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         cout << arr[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        solve(s);
    }
    return 0;
}
