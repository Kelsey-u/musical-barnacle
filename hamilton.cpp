#include<bits/stdc++.h>
using namespace std;
int n,dp[1<<20][21];
int dist[21][21];
int main(){
    memset(dp,0x3f,sizeof(dp));
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>dist[i][j];
        }
    }
    dp[1][0];
    for(int s=1;s<(1<<n);s++){
        for(int j=0;j<n;j++){
            if((s>>j)&1){
                for(int k=0;k<n;k++){
                    if(s^(1<<j)>>k&1){
                        dp[s][j]=min(dp[s][j],dp[s^(1<<j)][k]+dist[k][j]);
                    }
                }
            }
        }
    }
    cout<<dp[(1<<n)-1][n-1];
    return 0;
}