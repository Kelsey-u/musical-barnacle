#include<bits/stdc++.h>
using namespace std;
char a[105],b[105];
int dp[105][105];
const int INF=0x3f3f3f3f;
int main(){
    while(~scanf("%s%s",a+1,b+1)){
        int n=strlen(a+1);
        for(int i= 1;i<=n;i++){
            dp[i][i]=1;
        }
        for(int len=2;len<=n;len++){
            for(int i=1;i<=n;i++){
                int j=i+len-1;
                dp[i][j]=INF;
                if(b[i]==b[j]){
                    dp[i][j]=dp[i+1][j];
                }else{
                    for(int k=i;k<j;k++){
                        dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]);
                    }
                }
            }
        }
        for(int j=1;j<=n;++j){
            if(a[j]==b[j]){
                dp[1][j]=dp[1][j-1];
            }else{
                for(int k=1;k<j;++k){
                    dp[1][j]=min(dp[1][j],dp[1][k]+dp[k+1][j]);
                }
            }
        }
        printf("%d\n",dp[1][n]);
    }
    return 0;
}