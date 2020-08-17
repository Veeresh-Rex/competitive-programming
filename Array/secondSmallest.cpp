#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	for(int k=0;k<t;k++)
	{
	    int n;
	    cin>>n;
	    int *a=new int[n];
	    for(int i=0;i<n;i++)
	    {
	        cin>>a[i];
	    }
	    int firstLarg=INT_MIN;
	    int secondLarg=INT_MIN;
	    for(int i=0;i<n;i++)
	    {
	        if(a[i]>firstLarg)
	        {
	            secondLarg=firstLarg;
	            firstLarg=a[i];
	            
	        }
	        else if(secondLarg<a[i]&&a[i]!=firstLarg)
	                secondLarg=a[i];
	       //   else if(a[i]==firstLarg)
	       //             {
	       //                 secondLarg=firstLarg;
	       //             }
	    }
	    if(secondLarg==firstLarg||(secondLarg==INT_MIN))
	    {
	        cout<<"-1"<<endl;
	    }
	    else
	    cout<<secondLarg<<endl;
	    delete[] a;
	}
	return 0;
}
