//given task: find out the number of divisors to numbers upto 10^9 in [a,b] where (b-a)<=10000000 ie. We are allowed to create an array
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
      int a,b;
      cin>>a>>b;
      int arr[b-a+1];
      memset(arr,0,sizeof(arr));
      for(int i=1;i<=sqrt(b);i++)
      {
      	int first_div_by_i = ((a-1)/i+1)*i,sq=i*i,j;
      	for(j=first_div_by_i;j<=b;j+=i)
      	{
      		if(j<sq)
      			continue;
      		else
      			if(j==sq)
      				arr[j-a]++;
      			else
      				arr[j-a]+=2;
      	}
      }
      int m_d=-1,c=0;
      for(int j=a;j<=b;j++)
      	{
      		if(arr[j-a]>m_d)
      		{
      			m_d = arr[j-a];
      			c=1;
      		}
      		else
      			if(arr[j-a]==m_d)
      			c++;
      	}
      	cout<<c+1<<endl;
    }
    return 0;
}