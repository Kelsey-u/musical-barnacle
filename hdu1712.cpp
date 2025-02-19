#include<bits/stdc++.h>
using namespace std;
const int N=105;
int w[N][N],c[N][N];
int dp[N];
int n,m;
int main(){
    while(scanf("%d %d",&n,&m)&&n&&m){
        for(int i=1;i<=n;i++){
            for(int k=1;k<=m;k++){
                scanf("%d",&w[i][k]);
                c[i][k] = k;
            }
        }
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++){
            for(int j=m;j>=0;j--){
                for(int k=1;k<=m;k++){
                    if(j>=c[i][k]){
                        dp[j]=max(dp[j],dp[j-c[i][k]]+w[i][k]);
                    }
                }
            }
        }
        printf("%d\n",dp[m]);
    }
    return 0;
}