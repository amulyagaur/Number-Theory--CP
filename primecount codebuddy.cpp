#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
//function to build the segment tree
long long int prime[10000001]={0};

void buildTree(long long int *tree,long long int *a,long long int index,long long int s,long long int e)
{
	//base case
	if(s>e)
		return;
	//reached leaf node
	if(s==e)
	{
		tree[index]=a[s];
		return ;
	}
	//now build the segment tree in bottom up manner
	long long int m = (s+e)/2;
	buildTree(tree,a,2*index,s,m);
	buildTree(tree,a,2*index+1,m+1,e);
	tree[index]= tree[2*index]+tree[2*index+1];
	return;
}

//function to query the segment tree for RSQ
long long int query(long long int *tree,long long int index,long long int s,long long int e,long long int qs,long long int qe)
{
	//base case: if query range is outside the node range
	if(qs>e || s>qe)
		return 0;
	//complete overlap
	if(s>=qs && e<=qe)
		return tree[index];
	//now partial overlap case is executed
	long long int m = (s+e)/2;
	long long int left_ans = query(tree,2*index,s,m,qs,qe);
	long long int right_ans = query(tree,2*index+1,m+1,e,qs,qe);
	return left_ans+right_ans;
}

//function to update a value at position to "pos"
void updateNode(long long int *tree,long long int index,long long int s,long long int e,long long int pos,long long int val)
{
	if(pos<s || pos>e)
		return ;
	if(s==e)
	{
		tree[index] = val;
		return ;
	}
	long long int m = (s+e)/2;
	updateNode(tree,2*index,s,m,pos,val);
	updateNode(tree,2*index+1,m+1,e,pos,val);
	tree[index] = tree[2*index]+tree[2*index+1];
	return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for(long long i=2;i*i<=10000000;i++)
    {
    	if(prime[i]==0)
    	{
    		for(long long j=i*i;j<=10000000;j+=i)
    			prime[j]=1;
    	}
    }
    										 //input array	
    long long int n;
    cin>>n;
    long long int a[n],arr[n];
    for(long long int i=0;i<n;i++)
    {
    	cin>>arr[i];
    	if(prime[arr[i]]==0)
    		a[i]=1;
    	else
    		a[i]=0;
    }
    													//size of input array
    long long int *tree = new long long int[4*n+1];                                    //array to store the segment tree
    long long int index = 1;													//index of 1st node
    long long int s =0,e=n-1;
    buildTree(tree,a,index,s,e);
    long long int q;
    cin>>q;
    while(q--)
    {
    	long long int d,x,y;
    	cin>>d>>x>>y;
    	if(d==0)
    	{
    		arr[x-1]=y;
    		if(prime[y]==0)
    		{
    			a[x-1]=1;
    			updateNode(tree,index,s,e,x-1,1);
    		}
    		else
    		{
    			a[x-1]=0;
    			updateNode(tree,index,s,e,x-1,0);
    		}
    	}
    	else
    	{
    		cout<<(long long int)query(tree,index,s,e,x-1,y-1)<<endl;
    	}
    }									//now tree has been built
  
    return 0;
}