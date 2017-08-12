#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
long long int p(long long int x,long long int a,long long int b,long long int c)
{
	long long int res = a*x*x+b*x+c;
	return res;
}
long long int b_s(long long int low,long long int high,long long int a,long long int b,long long int c,long long int k)
{
	long long int res =-1;
	while(low<=high)
	{
		long long int mid  = low + (high-low)/2;
		if(p(mid,a,b,c)>=k)
		{
			res = mid;
			high = mid-1;
		}
		else
			if(p(mid,a,b,c)<k)
				low = mid+1;
			else
				high = mid-1;
	}
	return res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
    	long long a,b,c,k;
    	cin>>a>>b>>c>>k;
    	cout<<b_s(0,100000,a,b,c,k)<<endl;
    }
    return 0;
}
