#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 	long long a[1001];
 	a[0]=0;
 	a[1]=1;
 	for(int i=2;i<=1000;i++)
 		a[i]=(a[i-1]%1000000007+a[i-2]%1000000007)%1000000007;
 	int t;
 	cin>>t;
 	while(t--)
 	{
 		int d;
 		cin>>d;
 		cout<<a[d]<<endl;
 	}
    return 0;
}
