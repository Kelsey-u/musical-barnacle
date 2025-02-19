#include <bits/stdc++.h>//万能头文件
using namespace std;
int n,p;//输入必备
int a[13];//输出必备
int c[13][13];//杨辉三角必备
bool b[13];//判重必备
void dfs(int dep,int s)
{
	if(s>p)//如果现在累加的数已经超过了给定的数，就返回
		return;
	if(dep>n)//如果已经搜完了n个数，就返回
	{
		if(s==p)//如果答案跟给定的数相等
		{
			cout<<a[1];
			for(int i=2;i<=n;i++)
				cout<<" "<<a[i];//输出
			exit(0);//终止程序
		}
		return;//如果没有输出答案，就返回
	}
	for(int i=1;i<=n;i++)
	{
		if(b[i]==false)//如果当前这个数没有用过
		{
			b[i]=true;//标记成用过
			a[dep]=i;//保存第dep个取的数
			dfs(dep+1,s+i*c[n][dep]);
			b[i]=false;//注意这里要将状态回归，不然TLE
		}
	}
}
int main()
{
	cin>>n>>p;//输入
	c[1][1]=1;
	for(int i=2;i<=n;i++)
		for(int j=1;j<=i;j++)
			c[i][j]=c[i-1][j]+c[i-1][j-1];//生成杨辉三角
	dfs(1,0);//开启深搜之旅
	return 0;
}