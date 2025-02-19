#include<stdio.h>
int main()
{
    char a;
    int x;
    int m,n;
    scanf("%c %d %d",&a,&m,&n);
    if(a=='+')
    {
        x=1;
    }
    else if(a=='-')
    {
        x=2;
    }
    else if(a=='*')
    {
        x=3;
    }
    else if(a=='/')
    {
        x=4;
    }
    switch (x)
    {
    case 1:
        printf("%d",m+n);
        break;
    case 2:
        printf("%d",m-n);
        break;
    case 3:
        printf("%d",m*n);
        break;
    case 4:
        printf("%d",m/n);
        break;
    }
    return 0;
}