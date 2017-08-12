#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ull long long
#define MODULO 1000000007
int  a[1000001]={0};
 int arr[1000001]={0};
//vector< std::vector<long long> >v(10000);
int mulmod(int a,int b,int c){
    long long x = 0,y=a%c;
    while(b > 0){
        if(b%2 == 1){
            x = (x+y)%c;
        }
        y = (y*2)%c;
        b /= 2;
    }
    return x%c;
}
int modulo_exp(int a,int b,int c)
{
    long long x=1,y=a; // long long is taken to avoid overflow of intermediate results
    while(b > 0){
        if(b%2 == 1){
            x = mulmod(x,y,c);
        }
        y = mulmod(y,y,c); // squaring the base
        b /= 2;
    }
    return x%c;
}



int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    for(int  i=2;i<=1000000;i+=2)
    	a[i]=2;
    for(int i=3;i<=1000000;i+=2)
    {
    	if(a[i]==0)
    	{
    		a[i]=i;
    		for(long long j=i*i;j<=1000000;j+=i)
    		{
    			if(a[j]==0)
    				a[j]=i;
    		}
    	}
    }
    arr[0]=0;
    arr[1]=1;
    for(int i=2;i<=100000;i++)
    {
    	int div_sum = 0;
    	unordered_map<int,int> m;
    	//int x[1000000]
    	int num = i;
    	while(num>1)
    	{
    		m[a[num]]++;
    		num = num/a[num];
    	}
    	unordered_map<int,int> :: iterator it;
    	for(it = m.begin();it!=m.end();it++)
    	{
    		div_sum = (div_sum%1000000007+(it->second)%1000000007)%1000000007;
    	}
    	if(div_sum==m.size())
    	arr[i]=1;
    }
    for(int i=1;i<=1000000;i++)
    arr[i]+= arr[i-1];
    
    int t;
    cin>>t;
    while(t--)
    {
    	int l,r,cou=0;
    	scanf("%d %d",&l,&r);
    	if(l!=0)
    	cou = arr[r]-arr[l-1];
    	else
    	cou =  arr[r]; 
        printf("%d\n",modulo_exp(cou%1000000007,(r-l+1)%1000000007,1000000007));
    }   
    return 0;
}