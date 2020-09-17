#include<bits/stdc++.h>
using namespace std;
//#pragma GCC optimize("O2") 
#define gc getchar_unlocked
#define Endl "\n"
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
#define clr(x) memset(x, 1, sizeof(x))
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
#define nn 1000001
bool isPrime[nn];
void solve()
{
clr(isPrime);
isPrime[0]=isPrime[1]=0;
for(int i=4;i<=nn;i+=2)
{
    isPrime[i]=0;
}
for(int i=3;i*i<=nn;i+=2)
{
    if(isPrime[i])
    {
        for(int j=i*i;j<=nn;j+=i)
        {
            isPrime[j]=0;
        }
    }
}
// for(int i=0;i<100;i++)
// {
//     if(isPrime[i])
//     {
//         cout<<i<<" ";
//     }
// }
// cout<<"\n";

}
int32_t main()
 {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	int t;
	cin>>t;
	solve();
	while(t--)
	{
	    ll n;
	    cin>>n;
	    int count=0;
	    for(ll i=2;i<=sqrt(n);i++)
	    {
	        if(isPrime[i])
	        {
	            
	            //cout<<i<<" ";
	            count++;
	        }
	    }
	    cout<<count<<"\n";
	    
	}
	return 0;
}
