#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

double ans;
int size[100010];
int head[100100];
struct Node{
	int num,next;
}edge[200100];

int cnt;
void add(int x,int y){
	edge[cnt].next=head[x];
	edge[cnt].num=y;
	head[x]=cnt++;
	edge[cnt].next=head[y];
	edge[cnt].num=x;
	head[y]=cnt++;
}

void dfs(int x,int fa,double d){
	size[x]=0;
	int sum=0;
	for(int i=head[x];i!=-1;i=edge[i].next) 
		sum++;
	if(fa) sum--;
	ans+=d;
	for(int i=head[x];i!=-1;i=edge[i].next){
		int v=edge[i].num;
		if(fa==v) continue;
		dfs(v,x,d/sum);
	}
}

int main(){
	int n;
	int x,y;
	while(~scanf("%d",&n)){
		memset(head,-1,sizeof(head));
		cnt=0;
		for(int i=1;i<n;i++){
			scanf("%d%d",&x,&y);
			add(x,y);
		}
		ans=-1;
		dfs(1,0,1);
		printf("%.8f\n",ans);
	}
}
