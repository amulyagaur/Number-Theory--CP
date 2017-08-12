#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a[151];
    a[0]=1;
    int i2=0,i3=0,i5=0;
    int n_2 = 2,n_3=3,n_5=5;
    for(int i=1;i<=150;i++)
    {
    	int n_u =min(n_2,min(n_3,n_5));
    	a[i]=n_u;
    	if(n_u==n_2)
    	{
    		i2++;
    		n_2 = a[i2]*2;
    	}
    	if(n_u==n_3)
    	{
    		i3++;
    		n_3 = a[i3]*3;
    	}
    	if(n_u==n_5)
    	{
    		i5++;
    		n_5 = a[i5]*5;
    	}
    }
    cout<<a[149]<<endl;
    return 0;
}
