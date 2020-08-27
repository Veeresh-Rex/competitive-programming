/* Input  : n = 4
Output : 1
Prime factorization = 2, 2  and 2 + 2 = 4
Therefore, 4 is a smith number

Input  : n = 6
Output : 0
Prime factorization = 2, 3  and 2 + 3 is
not 6. Therefore, 6 is a smith number

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
#define max 100001
vl spf(max);
void solve()
{

    spf[1]=1;
    for (ll i=2;i<max;i++)
        spf[i]=i;
    for (ll i=4;i<max;i+=2)
        spf[i]=2;
    for (ll i=3;i*i<max;i++)
    {
        if (spf[i]==i)
        {
            for (ll j=i*i;j<max;j+=i)
            {
                if (spf[j]==j)
                    spf[j]=i;
            }
        }
    }

}
vi getFactorization(int n)
{
    vi res;
    while (n!=1)
    {
        
        res.pb(spf[n]);
        n=n/spf[n];
    }
    return res;
}
int sumOf(int n)
{
    int sum=0, rem;
    while (n!=0)
    {
        rem=n%10;
        sum+=rem;
         n=n/10;
    }
    return sum;

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
        int n;
        cin>>n;
        solve();
        vector <int> p = getFactorization(n);
        long sum =0;
        for (int i=0; i<p.size(); i++)
        {
            if (p[i]==n)
            {
                continue;
            }
            sum +=sumOf(p[i]);
        }
        if (sum==sumOf(n))
            cout<<"1";
        else
            cout<<"0";


        cout << endl;

    }
    return 0;
}
