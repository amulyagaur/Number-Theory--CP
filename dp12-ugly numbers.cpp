#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
  	vector<int> ug;
  	ug.push_back(1);
  	int i3=0,i2=0,i5=0;
  	for(int i=1;i<150;i++)
  	{
  		int next = min(ug[i2]*2,min(ug[i3]*3,ug[i5]*5));
  		if(next==ug[i2]*2)
  		{
  			i2++;
  		}
  		if(next==ug[i3]*3)
  		{
  			i3++;
  		}
  		if(next==ug[i5]*5)
  		{
  			i5++;
  		}
  		ug.push_back(next);
  	}
  	int t;
  	cin>>t;
  	while(t--)
  	{
  		int d;
  		cin>>d;
  		cout<<ug[d-1]<<endl;
  	}
    return 0;
}
