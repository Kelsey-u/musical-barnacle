#include<bits/stdc++.h>
using namespace std;
const int N=100005;
long long n,k,e[N],sum[N],dp[N];
long long ds[N];
int q[N],head=0,tail=1;
long long que_max(int j){
    ds[j]=dp[j-1]-sum[j];
    while(head<=tail&&ds[q[tail]]<ds[j])tail--;
    q[++tail]=j;
    while(head<=tail&&q[head]<j-k)head++;
    return ds[q[head]];
}
int main(){
    cin>>n>>k;
    sum[0]=0;
    for(int i=1;i<=n;i++){
        cin>>e[i];sum[i]=sum[i-1]+e[i];
    }
    for(int i=1;i<=n;i++){
        dp[i]=que_max(i)+sum[i];
    }
    cout<<dp[n];
    return 0;
}