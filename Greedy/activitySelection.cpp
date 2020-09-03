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
int compare(pii &a, pii &b)
{
    return a.second < b.second;
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
        /* code */

        int n;
        cin >> n;
        vector<pii> activity;
        vi f;
        vi s;
        int a, b;
        for (int i = 0; i < n; i++)
        {
            cin >> a;
            s.pb(a);
        }
        for (int i = 0; i < n; i++)
        {
            cin >> b;
            f.pb(b);
        }
        for (int i = 0; i < n; i++)
        {
            activity.pb(mp(s[i], f[i]));
        }
        sort(activity.begin(), activity.end(), compare);
        // for (auto i : activity)
        //     cout << i.first << " " << i.second << "\n";
        int activityCount = 1;
        pii prev = activity[0];
        for (int i = 1; i < n; i++)
        {
            if (prev.second <= activity[i].first)
            {
                activityCount++;
                prev = activity[i];
            }
        }
        cout << activityCount << "\n";
    }
    return 0;
}
