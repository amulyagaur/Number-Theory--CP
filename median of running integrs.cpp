#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int main()
{
    
    int n;
    scanf("%d",&n);
    deque<int> q;
    for(int i=1;i<=n;i++)
    {
        int d;
        scanf("%d",&d);
        if(q.size()==0)
            q.push_back(d);
        else
            q.insert(lower_bound(q.begin(),q.end(),d),d);
        
        if(i%2!=0)
            printf("%d\n",q[i/2]);
        else
            printf("%d\n",q[i/2-1]);
    }
    return 0;
}
