#include<bits/stdc++.h>
using namespace std;
const int n = 100005;
struct ndoe
{
    char value;
    int lson,rson;
}tree[n];
int index = 1;
int newnode(char val)
{
    tree[index].value=val;
    tree[index].lson=0;
    tree[index].rson=0;
    return index++;
}
void insert(int &father,int child,int l_r)
{
    if(l_r==0)  tree[father].lson=child;
    else    tree[father].rson=child;
}
int buildtree()
{
    int A=newnode('A');int B=newnode('B');int C=newnode('C');int D=newnode('D');
    int E=newnode('E');int F=newnode('F');int G=newnode('G');int H=newnode('H');
    int I=newnode('I');int J=newnode('J');int K=newnode('K');int L=newnode('L');
    insert(E,B,0);insert(E,G,1);
    insert(B,A,0);insert(B,D,1);
    insert(G,F,0);insert(G,I,1);
    insert(D,C,0);insert(I,H,0);
    int root=E;
    return root;
}
int main()
{
    int root=buildtree();
    queue<int>q;
    q.push(root);
    while(q.size())
    {
        int tmp = q.front();
        cout<<tree[tmp].value<<" ";
        q.pop();
        if(tree[tmp].lson!=0)q.push(tree[tmp].lson);
        if(tree[tmp].rson!=0)q.push(tree[tmp].rson);
    }
    return 0;
}