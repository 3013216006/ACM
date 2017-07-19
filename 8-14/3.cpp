#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
using namespace std;
struct Node{
	int num,next,v;
}edge[200000];
priority_queue<int> Q;
int head[100010],cnt;
int dp[100010][3],dp1[100010],dp2[100010],a[100010],dp3[100010],dp4[100010],mytmp[100010];
void add(int x,int y,int v){
	edge[cnt].next=head[x];
	edge[cnt].num=y;
	edge[cnt].v=v;
	head[x]=cnt++;
}
void dfs(int x,int fa){
	dp[x][0]=a[x];
	for(int i=head[x];i!=-1;i=edge[i].next){
		int v=edge[i].num;
		if(v==fa) continue;
		dfs(v,x);
		mytmp[v]=dp[v][0]-edge[i].v*2;
		if(mytmp[v]>0)
			dp[x][0]+=mytmp[v];
	}
}

void dfs1(int x,int fa){
	dp4[x]=dp[x][0];
	for(int i=head[x];i!=-1;i=edge[i].next){
		int v=edge[i].num;
		if(v==fa) continue;
		int haha=dp[x][0];
		if(mytmp[v]>0){
			dp1[v]=max(dp[v][0],dp1[x]);
			haha-=(mytmp[v]);
		}
		else dp1[v]=max(dp[v][0],dp1[x]+mytmp[v]);
		dfs1(v,x);
		dp4[x]=max(dp4[x],haha+dp4[v]-edge[i].v);
	}
}
priority_queue<int> P;
void dfs2(int x,int fa){
	for(int i=head[x];i!=-1;i=edge[i].next){
		int v=edge[i].num;
		if(v==fa) continue;
		dfs2(v,x);
	}
	while(!Q.empty()) Q.pop();
	int ans=dp1[x],sum=1,tmp;
	dp2[x]=x;
	Q.push(-ans);
	for(int i=head[x];i!=-1;i=edge[i].next){
		int v=edge[i].num;
		if(v==fa) continue;
		tmp=dp1[x];
		if(mytmp[v]>0)
			tmp=tmp-mytmp[v];
		tmp+=(dp4[v]-edge[i].v);
		if(tmp>ans) {
			ans=tmp;
			dp2[x]=v;
		}
		Q.push(-tmp);
		sum++;
		if(sum>2) Q.pop();
	}
	int l=1;
	while(!Q.empty()) P.push(-Q.top()),Q.pop();
	while(!P.empty()) {dp[x][l++]=P.top();P.pop();}
}

void dfs3(int x,int fa,int y){
	int tmp=dp[fa][1];
	if(dp2[fa]==x) tmp=dp[fa][2];
	if(dp[x][0]-y*2>0) tmp-=(dp[x][0]-y*2);
	tmp+=(dp[x][0]-y);
	if(tmp>dp[x][1]) dp[x][1]=tmp,dp2[x]=fa;
		else if(tmp>dp[x][2]) dp[x][2]=tmp;
	for(int i=head[x];i!=-1;i=edge[i].next){
		int v=edge[i].num;
		if(v==fa) continue;
		dfs3(v,x,edge[i].v);
	}
}

int main(){
	int T,x,y,z,n,cas=1;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		cnt=0;
		memset(head,-1,sizeof(head));
		for(int i=1;i<n;i++){
			scanf("%d%d%d",&x,&y,&z);
			add(x,y,z);
			add(y,x,z);
		}
		memset(dp1,0,sizeof(dp1));
		dfs(1,0);
		dp1[1]=dp[1][0];
		/*
		for(int i=1;i<=n;i++)
			cout << i << " " << dp[i][0] << endl;
			cout << endl;
			*/
		dfs1(1,0);
		/*
		for(int i=1;i<=n;i++)
			cout << i << " " << dp4[i] << endl;
			*/
		dfs2(1,0);
		/*
		for(int i=1;i<=n;i++)
			cout << i << " " << dp[i][1] << " " << dp[i][2] << endl << dp2[i] << endl;
		*/
		dfs3(1,0,dp1[1]);
		/*
		for(int i=1;i<=n;i++)
			cout << i << " " << dp[i][1] << " " << dp[i][2] << endl << dp2[i] << endl;
			*/
		printf("Case #%d:\n",cas++);
		for(int i=1;i<=n;i++)
			printf("%d\n",dp[i][1]);
	}
}
