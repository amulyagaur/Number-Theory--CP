#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a[1001][801];
    for(int i=0;i<=1000;i++)
    {
    	for(int j=0;j<=i;j++)
    	{
    		if(j==0 || i==j)
    			a[i][j]=1;
    		else
    			a[i][j] = (a[i-1][j]%1000000007 + a[i-1][j-1]%1000000007)%1000000007;
    	}
    }
    int t;
    cin>>t;
    while(t--)
    {
      int n,r;
      cin>>n>>r;
      cout<<a[n][r]<<endl;
    }
    return 0;
}
