#include<stdio.h>
typedef struct island
{
    int a;
    struct island *next;
}island;
void dis(island *start)
{
    island *i = start;
    for(;i!=NULL;i=i->next)
    {
        printf("a = %d\n",i->a);
    }
}
int main()
{
    island ss = {1,NULL};
    island bb ={2,NULL};
    ss.next = &bb;
    island cc = {5,NULL};
    ss.next = &cc;
    cc.next = &bb;
    dis(&ss);
    return 0;
}