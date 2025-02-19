#include<bits/stdc++.h>
using namespace std;
const int N=1011;
int w[N],c[N];
/*int dp[2][N];
int solve(int n,int C){
    int now=0,old=1;
    for(int i=1;i<=n;i++){
        swap(old,now);
        for(int j=0;j<=C;j++){
            if(c[i]>j)dp[now][j]=dp[old][j];
            else    dp[now][j]=max(dp[old][j],dp[old][j-c[i]]+w[i]);
        }
    }
    return dp[now][C];
}*/
int dp[N];
int solve(int n,int C){
    for(int i=1;i<=n;i++){
        for(int j=C;j>=c[i];j--){
            dp[j]=max(dp[j],dp[j-c[i]]+w[i]);
        }
    }
    return dp[C];
}

int main(){
    int T;cin>>T;
    while(T--){
        int n,C;
        cin>>n>>C;
        for(int i=1;i<=n;i++)cin>>w[i];
        for(int i=1;i<=n;i++)cin>>c[i];
        memset(dp,0,sizeof(dp));
        cout<<solve(n,C)<<endl;
    }
    return 0;
}