#include<stdio.h>
int main()
{
    int m,n;
    for(m=1;m<=9;m++)
        {
            for(n=1;n<=m;n++)
                {
                    printf("%d*%d=%-2d ",m,n,m*n);
                }
                printf("\n");
        }
    return 0;
}