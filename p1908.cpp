#include<bits/stdc++.h>
using namespace std;
const int N=500010;
#define lowbit(x) ((x)&-(x))
int tree[N],ran[N],n;
struct point{int num,val;}a[N];
bool cmp(point x,point  y){
    if(x.val==y.val)return x.num<y.num;
    return x.val<y.val;
}
void update(int x,int d){
    while(x<=N){
        tree[x]+=d;
        x+=lowbit(x);
    }
}
int sum(int x){
    int ans=0;
    while(x>0){
        ans += tree[x];
        x -= lowbit(x);
    }
    return ans;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i].val);
        a[i].num=i;
    }
    sort(a+1,a+1+n,cmp);
    for(int i=1;i<=n;i++){
        ran[a[i].num]=i;
    }
    long long ans=0;
    for(int i=n;i>0;i--){
        update(ran[i],1);
        ans+=sum(ran[i]-1);
    }
    printf("%lld",ans);
    return 0;
}