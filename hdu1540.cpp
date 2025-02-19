#include<bits/stdc++.h>
using namespace std;
const int N=50010;
int ls(int p){return p<<1;}
int rs(int p){return p<<1|1;}
int tree[N<<2],pre[N<<2],suf[N<<2];
int history[N];
void pushup(int p,int len){
    pre[p]=pre[ls(p)];
    suf[p]=suf[rs(p)];
    if(pre[ls(p)]==(len-(len>>1)))pre[p]=pre[ls(p)]+pre[rs(p)];
    if(suf[rs(p)]==(len>>1)){suf[p]=suf[ls(p)]+suf[rs(p)];}
}
void build(int p,int pl,int pr){
    if(pl==pr){tree[p]=suf[p]=pre[p]=1;return;}
    int mid=(pl+pr)>>1;
    build(ls(p),pl,mid);
    build(rs(p),mid+1,pr);
    pushup(p,pr-pl+1);
}
void update(int x,int c,int p,int pl,int pr){
    if(pl==pr){
        tree[p]=suf[p]=pre[p]=c;return;
    }
    int mid=(pl+pr)>>1;
    if(x<=mid){
        update(x,c,ls(p),pl,mid);
    }else{
        update(x,c,rs(p),mid+1,pr);
    }
    pushup(p,pr-pl+1);
}
int query(int x,int p,int pl,int pr){
    if(pl==pr) return tree[p];
    int mid=(pl+pr)>>1;
    if(x<=mid){
        if(x+suf[ls(p)]>mid)return suf[ls(p)]+pre[rs(p)];
        else    return query(x,ls(p),pl,mid);
    }else{
        if(mid+pre[rs(p)]>=x)return pre[rs(p)]+suf[ls(p)];
        else    return query(x,rs(p),mid+1,pr);
    }
}
int main(){
    int n,m,x,tot;
    while (scanf("%d %d",&n,&m)>0)
    {
        build(1,1,n);
        tot=0;
        while(m--){
            char op[10];scanf("%s",op);
            if(op[0]=='Q'){scanf("%d",&x);printf("%d\n",query(x,1,1,n));}
            else if(op[0]=='D'){
                scanf("%d",&x);
                history[++tot]=x;
                update(x,0,1,1,n);
            }
            else{
                x=history[tot--];
                update(x,1,1,1,n);
            }
        }
    }
    return 0;
}