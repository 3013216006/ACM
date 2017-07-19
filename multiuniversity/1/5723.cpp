#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#define MAXN 100010
using namespace std;
struct Node{
	int x,y,z;
}a[MAXN*10];
int fa[MAXN],siz[MAXN],c[MAXN],cnt,head[MAXN];
struct Node1{
	int next,num,c;
}edge[MAXN*2];
void add(int x,int y,int c){
	edge[cnt].next=head[x];
	edge[cnt].num=y;
	edge[cnt].c=c;
	head[x]=cnt++;
	edge[cnt].next=head[y];
	edge[cnt].num=x;
	edge[cnt].c=c;
	head[y]=cnt++;
}

int find(int x){
	if(fa[x]==x) return x;
		else return fa[x]=find(fa[x]);
}

bool cmp(Node a,Node b){
	return a.z<b.z;
}

void dfs(int x,int f){
	fa[x]=f;
	siz[x]=1;
	for(int i=head[x];i!=-1;i=edge[i].next){
		int v=edge[i].num;
		if(v==f){
			c[x]=edge[i].c;
			continue;
		}
		dfs(v,x);
		siz[x]+=siz[v];
	}
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n,m;
		memset(head,-1,sizeof(head));
		cnt=0;
		scanf("%d%d",&n,&m);
		for(int i=0;i<m;i++){
			scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
		}
		for(int i=1;i<=n;i++)
			fa[i]=i;
		sort(a,a+m,cmp);
		long long ans1=0;
		for(int i=0;i<m;i++){
			int fax=find(a[i].x);
			int fay=find(a[i].y);
			if(fax!=fay){
				add(a[i].x,a[i].y,a[i].z);
				fa[fax]=fay;
				ans1+=a[i].z;
			}
		}
		dfs(1,0);
		double ans2=0;
		for(int i=2;i<=n;i++){
			ans2+=2.0*c[i]*siz[i]*(n-siz[i])/(1.0*n*(n-1));		
		}
		printf("%lld %.2f\n",ans1,ans2);
	}
}
