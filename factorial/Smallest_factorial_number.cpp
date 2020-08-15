/* 
https://practice.geeksforgeeks.org/problems/smallest-factorial-number/0


Given a number n. The task is to find the smallest number whose factorial contains at least n trailing zeroes.

Examples:
Input : n = 1
Output : 5
1!, 2!, 3!, 4! does not contain trailing zero.
5! = 120, which contains one trailing zero.

Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test case contains an integer n.

Output:
For each test case in a new line print the required output.

Constraints:
1 <= T <= 100
1 <= n <= 100

Example:
Input:
2
1
6
Output:
5
25



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
int traling(int n)
{
     int ans = 0;
    int i = 5;
    while (1)
    {
        if (n / (i) == 0)
        {
            break;
        }
        ans += n / (i);
        i *= 5;
    }
    return ans;
}
int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int num;
        cin >> num;
        for (int i = 5; i <= num*5; i += 5)
        {
            int k=traling(i);
            if(k>num)
            {
                cout<<i<<"\n";
                break;
            }
            if (k == num)
            {
                cout << i << "\n";
                break;
            }
        }

        // cout << traling(num) << "\n";
    }
    return 0;
}
