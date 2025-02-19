#include<bits/stdc++.h>
using namespace std;
struct stu
{
    int id;
    int c,m,e;
    int sum;
}st[305];
bool cmp(stu a,stu b){
    if(a.sum>b.sum)return true;
    else if(a.sum<b.sum)return false;
    else{
        if(a.c>b.c)return true;
        else if(a.c<b.c)return false;
        else{
            if(a.id>b.id)return false;
            else return true;
        }
    }
}

int main(){
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        st[i].id=i;
        cin>>st[i].c>>st[i].m>>st[i].e;
        st[i].sum=st[i].c+st[i].m+st[i].e;
    }
    sort(st+1,st+1+n,cmp);
    for(int i=1;i<=5;i++){
        cout<<st[i].id<<' '<<st[i].sum<<endl;
    }
    return 0;
}
