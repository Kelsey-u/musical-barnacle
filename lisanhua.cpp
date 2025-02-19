#include<bits/stdc++.h>
using namespace std;
const int N=5e6+5;
int olda[N];
int newa[N];
int main(){
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&olda[i]);
        newa[i]=olda[i];
    }
    sort(olda+1,olda+n+1);
    int cnt = n;
    for(int i=1;i<=cnt;i++){
        newa[i]=lower_bound(olda+1,olda+n+1,newa[i])-olda;
    }
    for(int i=1;i<=cnt;i++){
        printf("%d",newa[i]);
    }
    printf("\ncnt=%d",cnt);
    return 0;
}