#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int a[N],d[N];
int main(){
    int n;
    while(~scanf("%d",&n)){
        memset(a,0,sizeof(a));
        memset(d,0,sizeof(d));
        for(int i=1;i<=n;i++){
            int L,R;scanf("%d %d",&L,&R);
            d[L++];d[R+1]--;
        }
        for(int i=1;i<=n;i++){
            a[i] = a[i-1]+d[i];
            if(i!=n){
                printf("%d",a[i]);
            }
            else{
                printf("%d\n",a[i]);
            }
        }
    }
    return 0;
}