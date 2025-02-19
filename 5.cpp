#include<bits/stdc++.h>
using namespace std;
int main()
{
    char *a;
    a = (char * )malloc(sizeof(char)*(8e7+1000));
    int n;
    for(int i=1;i<=8e7+1000;i++)
    {
        char ch=getchar();
        if(ch!=' '&&ch!=EOF&&ch!='\n')
        {
            a[++n] = ch;
        }
        else if(ch==EOF)
        {
            break;
        }
    }
    
    return 0;
}