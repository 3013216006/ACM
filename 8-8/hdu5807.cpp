#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
struct Node{
	int num,next;
}edge[2510];
int head[52],cnt;

void add(int x,int y){
	edge[cnt].next=head[x];
	edge[cnt].num=y;
	head[x]=cnt++;
}

int abs(int x){
	if(x<0) return -x;
	return x;
}

long long dp[55][55][55][3];
int a[55],n,m,k,q;
long long mod=998244353ll;
long long getans(int x,int y,int z,int l){
	if(dp[x][y][z][l]!=-1) return dp[x][y][z][l];
	if(l==0)
	if(abs(a[x]-a[y])>k||abs(a[x]-a[z])>k||abs(a[y]-a[z])>k) return dp[x][y][z][l]=0;
	long long ret=0;
	if(l==0){
		ret=1;
		for(int i=head[x];i!=-1;i=edge[i].next){
			int v=edge[i].num;
			ret+=getans(v,y,z,1);
			if(ret>=mod) ret-=mod;
		}
	}
	else if(l==1){
		for(int i=head[y];i!=-1;i=edge[i].next){
			int v=edge[i].num;
			ret+=getans(x,v,z,2);
			if(ret>=mod) ret-=mod;
		}
	}
	else{
		for(int i=head[z];i!=-1;i=edge[i].next){
			int v=edge[i].num;
			ret+=getans(x,y,v,0);
			if(ret>=mod) ret-=mod;
		}
	}
	return dp[x][y][z][l]=ret;
}

int main(){
	int T,x,y,z;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d%d",&n,&m,&k,&q);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		memset(head,-1,sizeof(head));
		cnt=0;
		for(int i=0;i<m;i++){
			scanf("%d%d",&x,&y);
			if(x>y) {
				int tmp=x;
				x=y;
				y=tmp;
			}
			add(x,y);
		}
		memset(dp,-1,sizeof(dp));
		for(int i=n;i>0;i--)
			for(int j=n;j>0;j--)
				for(int k=n;k>0;k--){
					//for(int l=0;l<3;l++)
						getans(i,j,k,0);
					}
		for(int i=0;i<q;i++){
			scanf("%d%d%d",&x,&y,&z);
			printf("%lld\n",getans(x,y,z,0));
		}
	}
}
