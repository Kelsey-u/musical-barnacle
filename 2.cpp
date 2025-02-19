#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long v,n;
    scanf("%lld %lld",&v,&n);
    long long *a;
    a = (long long *)malloc(1000001*sizeof(long long));
    for(long long i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    long long sum=0;
    long long x;
    for(long long i=1;i<=n;i++)
    {
        sum += a[i];
        if(sum>v)
        {
            x=i-1;
            break;
        }
        else if(i==n&&sum<=v)
        {
            x=n;
        }
    }
    free(a);
    printf("%lld",x);
    return 0;
}