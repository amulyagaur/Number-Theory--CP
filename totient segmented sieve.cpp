#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int a[10000001]={0};
vector<int> prime; 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for(int i=2;i<=sqrt(10000000);i++)
    {
    	for(int j=i*i;j<=10000000;j+=i)
    		a[j]=1;
    }
    for(int i=2;i<=10000000;i++)
    {
    	if(a[i]==0)
    		prime.push_back(i);
    }
    long long m,n,i,j;
    cin>>m>>n;
    long long phi[n-m+1],r[n-m+1];
   	for(i=m;i<=n;i++)
   	{
   		phi[i-m]=i;
   		r[i-m]=i;
   	}
   	
   	for(i=0;(prime[i]*prime[i])<=n && i<prime.size();i++)
   	{
   		if (prime[i] != 0)
          j = m / prime[i];
        j *= prime[i];
        
        
        for(;j<=n;j+=prime[i])
        {
        	if(j<m)
        		continue;
        	else
        	{
        		phi[j-m] = phi[j-m]-phi[j-m]/prime[i];
        		while((r[j-m]%prime[i])==0)
        			r[j-m] = r[j-m]/prime[i];
        	}
        }
      
   	}
   	for(i = m;i<=n;i++)
   	{
   		if(r[i-m]>1)
   		phi[i-m]=phi[i-m]-phi[i-m]/r[i-m];
   		cout<<phi[i-m]<<endl;
   		
   	}
   	
    return 0;
}