#include<stdio.h>
int sushu(int x)
{
    for(int i=2;i<x;i++)
    {
        if(x%i==0)
        {
            return 0;
        }
        if(i==x-1&&x%i!=0)
        {
            return 1;
        }
    }
}
int duichen(int x)
{
    int rev=0;
    int ori=x;
    while(x>0)
    {
        rev = rev*10+x%10;
        x/=10;
    }
    if(rev==ori)
    {
        return 1;
    }
    else{
        return 0;
    }
}
int seven(int x)
{
    int sum=0;
    while(x>0)
    {
        sum += x%10;
        x/=10;
    }
    if(sum%7==0)
    {
        return 1;
    }
    else{
        return 0;
    }
}
int main()
{
    int n;
    int s=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        if(sushu(i)==1)
    {
        if(duichen(i)==1)
        {
            if(seven(i)==1)
            {
                s++;
            }
        }
    }
    }
    printf("%d",s);
    return 0;
}