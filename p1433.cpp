#include<bits/stdc++.h>
using namespace std;
int num[500010],maxn,minn,sum;

int max(int x,int y){
	return x>y?x:y;
}

int min(int x,int y){
	return x>y?y:x;
}

void dfs(int wait,int already,int need,int can){	//从前往后依次为 还需要拼凑得到的木棍数量 
	int i;											//				当前已经拼凑得到的木棍的长度 
	if(wait==0){	//如果已经完成所有的木棍的拼凑，则直接输出结果	需要得到的木棍的长度 
		printf("%d",need);							//				当前可以使用的最长木棍的长度 
		exit(0);
	}
	if(already==need){//如果当前拼凑出的木棍的长度等于需要得到的木棍的长度，则开始拼凑下一根 
		dfs(wait-1,0,need,maxn);
		return ;
	}
	for(i=can;i>=minn;i--)
		if(num[i] && i+already<=need){
			num[i]--;
			dfs(wait,already+i,need,i);
			num[i]++;
			if(already==0 || already+i==need)
				return ;
		}
}
	
int main(){
//	freopen("in.txt","r",stdin);
	int i,j,k,m,n,temp;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&k);
		if(k<=50){		//忽略长度小于等于50的木棍 
			sum+=k;
			num[k]++;
			minn=min(k,minn);
			maxn=max(k,maxn);
		}
	}
	temp=sum/2;
	for(i=maxn;i<=temp;i++)			//枚举每一种可能选定的长度 
		if(sum%i==0)
			dfs(sum/i,0,i,maxn);
	printf("%d",sum);
	return 0;
}