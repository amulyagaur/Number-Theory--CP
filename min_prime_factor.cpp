#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
long long  a[10000001]={0};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for(long long int i=2;i<=10000000;i+=2)
    	a[i]=2;
    for(long long int i=3;i<=10000000;i+=2)
    {
    	if(a[i]==0)
    	{
    		a[i]=i;
    		for(long long j=i*i;j<=10000000;j+=i)
    		{
    			if(a[j]==0)
    				a[j]=i;
    		}
    	}
    }
    
    int num;
    cin>>num;
    while(num!=1)
    {
    	int fac = a[num];
    	cout<<fac<<endl;
    	num = num/fac;
    }
    return 0;
}
