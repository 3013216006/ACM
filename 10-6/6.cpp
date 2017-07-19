#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
struct Node{
	int num,next;
}edge[200010];
int head[200020],cnt;
int fa[200020],dep[200020],son[200020],sum[200020];
void add(int x,int y){
	edge[cnt].num=y;
	edge[cnt].next=head[x];
	head[x]=cnt++;
}

int dfs(int x,int f,int d){
	fa[x]=f;
	dep[x]=d;
	son[x]=0;
	for(int i=head[x];i!=-1;i=edge[i].next){
		int v=edge[i].num;
		if(v!=f){
			son[x]++;
			dfs(v,x,d+1);
		}
	}
}

struct Node1{
	int x,y;
}a[100010];

bool cmp(Node1 a ,Node1 b){
	return a.y>b.y;
}

int main(){
	int T,cas=1;
	int n,m,x,y,k;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		son[n]=0;
		memset(head,-1,sizeof(int)*(n+10));
		memset(dep,0,sizeof(dep));
		cnt=0;
		for(int i=1;i<n;i++){
			scanf("%d%d",&x,&y);
			add(x,y);
			add(y,x);
		}
		dfs(1,0,0);
		printf("Case #%d:\n",cas++);
		for(int i=0;i<m;i++){
			scanf("%d",&k);
			for(int j=0;j<k;j++){
				scanf("%d",&a[j].x);
				a[j].y=dep[a[j].x];
			}
			sort(a,a+k,cmp);
			int ans=n-k;
			for(int j=0;j<k;j++){
				int v=a[j].x;
				if(son[v]>=2) ans++;
				if(son[v]==0) son[fa[v]]--;
			}
			printf("%d\n",ans);
			for(int j=0;j<k;j++){
				int v=a[j].x;
				if(son[v]==0) son[fa[v]]++; 
			}
		}
	}
}

