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
class MinNode
{
public:
    char data;
    unsigned freq;
    MinNode *left, *right;
    MinNode(char data, unsigned fr)
    {
        this->data = data;
        freq = fr;
        left = right = NULL;
    }
};
class compare
{
public:
    bool operator()(MinNode *a, MinNode *b)
    {
        return (a->freq > b->freq);
    }
};
void printCode(MinNode *node, string st)
{
    if (node == NULL)
        return;
    if (node->data != '$')
    {
        cout << node->data << " : " << st << "\n";
    }
    printCode(node->left, st + "0");
    printCode(node->right, st + "1");
}
void solve(int freq[], int n, string st)
{
    MinNode *l, *r, *current;
    priority_queue<MinNode *, vector<MinNode *>, compare> pq;
    for (int i = 0; i < n; i++)
    {
        //  auto *node = new MinNode(st[i], freq[i]);
        pq.push(new MinNode(st[i], freq[i]));
    }
    while (pq.size() != 1)
    {
        l = pq.top();
        pq.pop();
        r = pq.top();
        pq.pop();
        current = new MinNode('$', l->freq + r->freq);
        current->left = l;
        current->right = r;
        pq.push(current);
    }
    printCode(pq.top(), "");
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

        string st;
        cin >> st;
        int n = st.size();
        cout << st << "\n";
        int freq[n];
        for (int i = 0; st[i]; i++)
        {
            cin >> freq[i];
        }
        solve(freq, n, st);
        cout << "\n";
    }
    return 0;
}
