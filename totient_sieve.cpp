int a[10000001]={0};

for(int i=0;i<=10000000;i++)
    a[i]=i;
    for(int i=2;i<=10000000;i++)
    {
        if(arr[i]==i)
        {
        for(int j=i;j<=10000000;j+=i)
        {
            a[j]=a[j]-a[j]/i;   
        }
        }
    }