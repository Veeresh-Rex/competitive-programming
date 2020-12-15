//#pragma GCC optimize("O2") 
#define gc getchar_unlocked
#define Endl "\n"
#define fo(i, n) for (i = 0; i < n; i++)
#define Fo(i, k, n) for (i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
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
typedef vector<vl> vvl;
bool comp(pii a ,pii b)
{
    double x=(double)a.F/a.S;
    double y=(double)b.F/b.S;
    return x>y;
}
int32_t main()
 {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
	    int n,k;
	    cin>>n>>k;
	   // cout<<n<<" "<<k<<"\n";
	    vector<pii>knap;
	    int a,b;
	    for(int i=0;i<n;i++)
	    {
	        cin>>a>>b;
	        knap.pb(mp(a,b));
	    }
	    sort(knap.begin(),knap.end(),comp);
	   // cout<<knap.size()<<"\n";
	   // for(auto i:knap)
	   // {
	   //     cout<<i.F<<" "<<i.S<<" ";
	   // }
	    double sumMax=0.0;
	    for(int i=0;i<n;i++)
	    {
	        if(k==0)
	        {
	            break;
	        }
	        if(k>=knap[i].S)
	        {
	            k-=knap[i].S;
	            sumMax+=(double)knap[i].F;
	        }
	        else
	        {
	            sumMax=sumMax+((double)knap[i].F/knap[i].S)*k;
	            k=0;
	        }
	    }
	   cout<<fixed<<setprecision(2)<<sumMax<<"\n";
	}
	
	return 0;
}
