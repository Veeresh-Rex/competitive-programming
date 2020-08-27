/* Input:
2
10
35
Output:
2 3 5 7
2 3 5 7 11 13 17 19 23 29 31 
*/

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
void solve(int n)
{
    bool isPrime[n+1];
    memset(isPrime, true, sizeof(isPrime)); 
  
    for (int i=2;i*i<=n;i++)
    {
        if (isPrime[i])
        {
            for (ll j=i*i;j<=n;j=j+i)
            {
                isPrime[j]=0;
            }
        }
    }
    isPrime[0]=isPrime[1]=0;
   
    for (int i=0;i<=n;i++)
    {
        if (isPrime[i])
        {
            cout<<i<<" ";
        }
    }
    cout<<"\n";
}

int main()
 {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    solve(n);
	}
	return 0;
}
