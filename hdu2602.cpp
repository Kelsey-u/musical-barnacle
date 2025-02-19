#include<bits/stdc++.h>
using namespace std;
const int N=1011;
int w[N],c[N];
int dp[N][N];
int solve(int n,int C){
    for(int i=1;i<=n;i++){
        for(int j=0;j<=C;j++){
            if(c[i]>j)dp[i][j] = dp[i-1][j];
            else    dp[i][j] = max(dp[i-1][j],dp[i-1][j-c[i]]+w[i]);
        }
    }
    return dp[n][C];
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