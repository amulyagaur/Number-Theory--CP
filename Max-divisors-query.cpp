#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int a[10001]={0};
//function to build a tree for max-divisor query
void buildTree(int *tree,int index,int s,int e)
{
	if(s>e)
		return;
	if(s==e)
	{
		tree[index]=a[s];
		return ;
	}
	int m = (s+e)/2;
	buildTree(tree,index*2,s,m);
	buildTree(tree,index*2 + 1,m+1,e);
	tree[index] = max(tree[index*2],tree[index*2 +1]);
	return;
}
//function to query the max no. of divisors
int query(int *tree,int index,int s,int e,int qs,int qe)
{
	//base case: if query range is outside the node range
	if(qs>e || s>qe)
		return INT_MIN;
	//complete overlap
	if(s>=qs && e<=qe)
		return tree[index];
	//now partial overlap case is executed
	int m = (s+e)/2;
	int left_ans = query(tree,2*index,s,m,qs,qe);
	int right_ans = query(tree,2*index+1,m+1,e,qs,qe);
	return max(left_ans,right_ans);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //code to fill the array
    for(int i=1;i<=10000;i++)
    {
    	for(int j=i;j<=10000;j+=i)
    		a[j]++;
    }
    int *tree = new int[4*10000+1];
    int index =1;
    int s =1,e=10000;
    buildTree(tree,index,s,e);
    cout<<query(tree,index,s,e,100,500)<<endl;
    return 0;
}
