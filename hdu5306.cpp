#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e6+10;
ll sum[N<<2],ma[N<<2],se[N<<2],num[N<<2];
ll ls(ll p){return p<<1;}
ll rs(ll p){return p<<1|1;}
void pushup(int p){
    sum[p]=sum[ls(p)]+sum[rs(p)];
    ma[p]=max(ma[ls(p)],ma[rs(p)]);
    if(ma[ls(p)]==ma[rs(p)]){
        se[p]=max(se[ls(p)],se[rs(p)]);
        num[p]=num[ls(p)]+num[rs(p)];
    }
    else{
        se[p]=max(se[ls(p)],se[rs(p)]);
        se[p]=max(se[p],min(ma[ls(p)],ma[rs(p)]));
        num[p]=ma[ls(p)]>ma[rs(p)]?num[ls(p)]:num[rs(p)];
    }
}
void build(int p,int pl,int pr){
    if(pl==pr){
        scanf("%lld",&sum[p]);
        ma[p]=sum[p];se[p]=-1;num[p]=1;
        return;
    }
    ll mid=(pl+pr)>>1;
    build(ls(p),pl,mid);
    build(rs(p),mid+1,pr);
    pushup(p);
}
void addtag(int p,int x){
    if(x>=ma[p]){
        return;
    }
    sum[p]-=num[p]*(ma[p]-x);
    ma[p]=x;
}
void pushdown(int p){
    addtag(ls(p),ma[p]);
    addtag(rs(p),ma[p]);
}
void update(int l,int r,int p, int pl,int pr,int x){
    if(x>=ma[p]){
        return;
    }
    if(l<=pl&&pr<=r&&se[p]<x){
        addtag(p,x);
        return;
    }
    pushdown(p);
    ll mid=(pl+pr)>>1;
    if(l<=mid){
        update(l,r,ls(p),pl,mid,x);
    }
    if(r>mid){
        update(l,r,rs(p),mid+1,pr,x);
    }
    pushup(p);
}
int queryMax(int l,int r,int p,int pl,int pr){
    if(pl>l&&r>pr){return ma[p];}
    pushdown(p);
    int res=0;
    ll mid=(pl+pr)>>1;
    if(l<=mid)res=queryMax(l,r,ls(p),pl,mid);
    if(r>mid)res=max(res,queryMax(l,r,rs(p),mid+1,pr));
    return res;
}
int querySum(int l,int r,int p,int pl,int pr){
    if(l<=pl&&r>=pr)return sum[p];
    pushdown(p);
    ll res=0;
    ll mid=(pl+pr)>>1;
    if(l<=mid){
        res += querySum(l,r,ls(p),pl,mid);
    }
    if(r>mid){
        res+=querySum(l,r,rs(p),mid+1,pr);
    }
    return res;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m;scanf("%d %d",&n,&m);
        build(1,1,n);
        while(m--){
            int q,l,r,x;
            scanf("%d %d %d",&q,&l,&r);
            if(q==0){
                scanf("%d",&x);update(l,r,1,1,n,x);
            }
            if(q==1){
                printf("%d\n",queryMax(l,r,1,1,n));
            }
            if(q==2){
                printf("%lld\n",querySum(l,r,1,1,n));
            }
        }
    }
    return 0;
}