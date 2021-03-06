#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int n,m;
struct Node{
	int num,next,v;
}edge[2000100];
int head[1000010],cnt;

void add(int x,int y,int v){
	edge[cnt].num=y;
	edge[cnt].next=head[x];
	edge[cnt].v=v;
	head[x]=cnt++;
	edge[cnt].num=x;
	edge[cnt].next=head[y];
	edge[cnt].v=v;
	head[y]=cnt++;
}
long long ans=0;
int size[1000010];
void dfs(int x,int fa){
	size[x]=1;
	for(int i=head[x];i!=-1;i=edge[i].next){
		int v=edge[i].num;
		if(v==fa) continue;
		dfs(v,x);
		size[x]+=size[v];
		ans+=1ll*min(size[v],m)*edge[i].v;
	}
}

int main(){
	int x,y,v;
	while(~scanf("%d%d",&n,&m)){
		cnt=0;
		memset(head,-1,sizeof(head));
		for(int i=1;i<n;i++){
			scanf("%d%d%d",&x,&y,&v);
			add(x,y,v);
		}
		ans=0;
		dfs(1,0);
		cout << ans << endl;
	}
}
