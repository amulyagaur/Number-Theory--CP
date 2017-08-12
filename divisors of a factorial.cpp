#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
long long int a[50001]={0};
vector<long long int> p;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for(long long int i=2;i<=sqrt(50000);i++)
    {
    	for(long long int j=i*i;j<=50000;j+=i)
    		a[j]=1;
    }
    for(long long int i=2;i<=50000;i++)
    	if(a[i]==0)
    		p.push_back(i);
    	int t;
    	cin>>t;
    	while(t--)
    	{
    		long long res=1;
  	long long int n;
  	cin>>n;
  	map<long long int,long long int> m;
  	for(long long int i=0;p[i]<=n && i<p.size();i++)
  	{
  		long long int div=p[i],c=0;
  		while(div<=n)
  		{
  			c+= n/div;
  			div = div *p[i];
  		}
  		m[p[i]]=c;
  	}
  	map<long long int,long long int> :: iterator it;
  	for(it = m.begin();it!=m.end();)
  	{
  		res = (res%1000000007*((long long)it->second+1)%1000000007)%1000000007;
  		it++;
  	}
  	cout<<(long long)res<<endl;
  }
    return 0;
}