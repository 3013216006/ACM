#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
struct Node{
	int num,next;
}edge[2500];
int cnt,head[100];

void add(int x,int y){
	edge[cnt].next=head[x];
	edge[cnt].num=y;
	head[x]=cnt++;
}
long long dp[55][55][55];
long long mod=998244353ll;
int n,m,k,q;
int a[55];
int abs(int x){
	if(x<0) return -x;
	return x;
}

long long getans(int x,int y,int z){
	int xx=min(x,min(y,z));
	int zz=max(x,max(y,z));
	int yy=x+y+z-xx-zz;
	x=xx;
	y=yy;
	z=zz;
	if(dp[x][y][z]!=-1) return dp[x][y][z];
	long long ret=1;
	if(abs(a[x]-a[y])>k||abs(a[x]-a[z])>k||abs(a[y]-a[z])>k)
		return dp[x][y][z]=0;
	if(head[x]==-1||head[y]==-1||head[z]==-1) return dp[x][y][z]=ret;
	for(int i=head[x];i!=-1;i=edge[i].next)
		for(int j=head[y];j!=-1;j=edge[j].next)
			for(int k=head[z];k!=-1;k=edge[k].next){
				int v1=edge[i].num,v2=edge[j].num,v3=edge[k].num;
				ret+=getans(v1,v2,v3);
				if(ret>mod) ret-=mod;
			}
	return dp[x][y][z]=ret;
}
int x,y,z;
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d%d",&n,&m,&k,&q);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		memset(dp,-1,sizeof(dp));
		memset(head,-1,sizeof(head));
		cnt=0;
		for(int i=0;i<m;i++){
			scanf("%d%d",&x,&y);
			add(x,y);
		}
		for(int i=0;i<q;i++){
			scanf("%d%d%d",&x,&y,&z);
			printf("%lld\n",getans(x,y,z));
		}
	}
}
