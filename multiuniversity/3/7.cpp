#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
struct Node{
	int num,next;
}edge[200100];
int head[100100],in[100100];
long long ans[100100][2];
int siz[100100];
int cnt,n,x,y;
void add(int x,int y){
	in[x]++;
	in[y]++;
	edge[cnt].next=head[x];
	edge[cnt].num=y;
	head[x]=cnt++;
	edge[cnt].next=head[y];
	edge[cnt].num=x;
	head[y]=cnt++;
}

long long dfs(int x,int f){
	siz[x]=0;
	ans[x][0]=0;
	ans[x][1]=0x3f3f3f3f3f3f3f3f;
	int flag=0;
	for(int i=head[x];i!=-1;i=edge[i].next){
		int v=edge[i].num;
		if(v==f) continue;
		flag=1;
		dfs(v,x);
		siz[x]+=siz[v];
		long long tmp0=ans[x][0],tmp1=ans[x][1];
		tmp0=min(ans[x][1]+ans[v][1]+1,ans[x][0]+ans[v][0]+2);
		tmp1=min(ans[x][0]+ans[v][1]+1,ans[x][1]+ans[v][0]);
		ans[x][0]=tmp0;
		ans[x][1]=tmp1;
	}
	if(!flag) ans[x][1]=0,siz[x]=1,ans[x][0]=0x3f3f3f3f3f3f3f3f;
	return ans[x][siz[x]%2];
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		cnt=0;
		memset(head,-1,sizeof(head));
		memset(in,0,sizeof(in));
		for(int i=1;i<n;i++){
			scanf("%d%d",&x,&y);
			add(x,y);
		}
		for(int i=1;i<=n;i++)
		if(in[i]>1){
			printf("%lld\n",dfs(i,0));
			break;
		}
		if(n==2) puts("1");
		if(n==1) puts("0");
		/*
		for(int i=1;i<=n;i++){
			printf("%10d%10d\n",ans[i][0],ans[i][1]);
		}*/
	}
}
