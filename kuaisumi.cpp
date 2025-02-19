#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll fastpow(ll a,ll n,ll m){
    if(n==0)return 1;
    if(n==1)return a;
    ll tmp = fastpow(a,n/2,m);
    if(n%2==1){
        return tmp*tmp*a%m;
    }
    else{
        return tmp*tmp%m;
    }
}
int main(){
    ll a,m,n;
    cin>>a>>n>>m;
    cout<<fastpow(a,n,m);
    return 0;
}