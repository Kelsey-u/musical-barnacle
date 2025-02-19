#include<bits/stdc++.h>
using namespace std;
queue<int>mem;
int main()
{
    int hash[1003] = {0};
    int m,n;scanf("%d %d",&m,&n);
    int cnt = 0;
    while(n--)
    {
        int en;scanf("%d",&en);
        if(!hash[en])
        {
            ++cnt;
            mem.push(en);
            hash[en]=1;
            while(mem.size()>m)
            {
                hash[mem.front()] = 0;
                mem.pop();
            }
        }
    }
    printf("%d\n",cnt);
    return 0;
}