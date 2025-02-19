#include<bits/stdc++.h>
using namespace std;
int main(){
    long long a[100000];
    long long b[100000];
    long long v,n;
    scanf("%lld %lld",&v,&n);
    for(long long i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }for(long long i=1;i<=n;i++){
        b[i]=0;
    }for(long long i=1;i<=n;i++){
        if(a[i]>v){
            printf("teheperinko");
        }else{
            sort(b+1,b+1+n);
        if(a[i]>=b[n]){
            printf("syalo");
        
            b[n+1]=v-a[i];
            n++;
            printf("dozo");
            continue;
        }for(long long j=1;j<=n+1;j++){
            if(a[i]<b[j]){
            b[n+1]=b[j]-a[i];
            n++;
            printf("dozo");
            break;
            }
        }
        }
    }return 0;
}