#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
using namespace std;
queue<int> Q;
int b[100010],in[100010];
double a[100010];
struct Node{
	int num,next;
}edge[100010];
int head[100010],cnt;

void add(int x,int y){
	edge[cnt].next=head[x];
	edge[cnt].num=y;
	head[x]=cnt++;
}

int main(){
	int n,m,x,y;
	double v;
	while(~scanf("%d%d",&n,&m)){
		memset(a,0,sizeof(a));
		memset(head,-1,sizeof(head));
		memset(in,0,sizeof(in));
		cnt=0;
		for(int i=1;i<n;i++){
			scanf("%d%d",&x,&y);
			add(y,x);
			in[x]++;
		}
		for(int i=1;i<=n;i++)
			scanf("%d",&b[i]);
		for(int i=1;i<=m;i++){
			scanf("%d%lf",&x,&v);
			a[x]+=v;
		}
		for(int i=1;i<=n;i++)
			if(in[i]==0) Q.push(i);
		double ans=0;
		while(!Q.empty()){
			int tmp=Q.front();
			Q.pop();
			ans=max(ans,a[tmp]+b[tmp]);
			for(int i=head[tmp];i!=-1;i=edge[i].next){
				int v=edge[i].num;
				a[v]+=a[tmp];
				in[v]--;
				if(in[v]==0) Q.push(v);
			}
		}
		printf("%.6f\n",ans);
	}
}
