#include<bits/stdc++.h>
using namespace std;
const int N=100010;
int n,C,dp[N];
int w[N],c[N],m[N];
int new_n;
int new_w[N],new_c[N],new_m[N];
int main(){
    cin>>n>>C;
    for(int i=1;i<=n;i++)cin>>w[i]>>c[i]>>m[i];
    /*for(int i=1;i<=n;i++){
        for(int j=C;j>=c[i];j--){
            for(int k=1;k<=m[i]&&k*c[i]<=j;k++){
                dp[j]=max(dp[j],dp[j-k*c[i]]+k*w[i]);
            }
        }
    }*/
    int new_n=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m[i];j<<=1){
            m[i] -= j;
            new_c[++new_n] = j*c[i];
            new_w[new_n] = j*w[i];
        }
        if(m[i]){
            new_c[++new_n] = m[i]*c[i];
            new_w[new_n] = m[i]*w[i];
        }
    }
    for(int i=1;i<=new_n;i++){
        for(int j=C;j>=new_c[i];j--){
            dp[j] = max(dp[j],dp[j-new_c[i]]+new_w[i]);
        }
    }
    cout<<dp[C]<<endl;
    return 0;
}