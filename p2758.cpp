#include<bits/stdc++.h>
using namespace std;
char a[4005],b[4005];
int lena,lenb,dp[4005][4005],k;//f(i,j)表示将A串前i个字符改为B串前j个字符需要的步数
int main() {
   cin>>a>>b;
   lena=strlen(a);lenb=strlen(b);
   for(int i=lena;i>=1;i--) a[i]=a[i-1];
   for(int i=lenb;i>=1;i--) b[i]=b[i-1];//初始化
   for(int i=i;i<=lena;i++){
      for(int j=1;j<=lenb;j++){
         if(a[i]==b[j]){
            dp[i][j]=dp[i-1][j-1];
         }else{
            dp[i][j]=min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1;
         }
      }
   }
   printf("%d",dp[lena][lenb]);
   return 0;
}