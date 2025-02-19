#include<stdio.h>
int find(int a)
{
    int x =0;
    for(int i=1;i<a;i++)
    {
        if(a%i==0)
        {
            x++;
        }
    }
    return x;
}
int main()
{
    int m;
    scanf("%d",&m);
    int arr[2000][2];
    for(int i=1;i<=m;i++)
    {
        scanf("%d",&arr[i][1]);
        arr[i][2] = find(arr[i][1]);
    }
    
    return 0;
}