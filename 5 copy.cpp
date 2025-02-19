#include<bits/stdc++.h>
using namespace std;
int main()
{
    list<char>node;
    char ch;
    while(1)
    {
        scanf("%c",&ch);
        if(ch=='\n')
        {
            break;
        }
        if(ch!=' ')
        {
            node.push_back(ch);
        }
    }
    auto it = node.begin();
    while(node.size()>1)
    {
        for(int i=1;i<2;i++)
        {
            it++;
            if(it==node.end())
            {
                it=node.begin();
            }
        }
        auto next = ++it;
        if(next==node.end())
        {
            next = node.begin();
        }
        node.erase(--it);
        it = next;
    }
    cout<<*it;
    return 0;
}