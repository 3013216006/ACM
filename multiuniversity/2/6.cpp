#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
long long mod=1000000007ll;
int tim;
long long ans;
struct Node{
	int num,next;
}edge[400020];
long long myget(long long x,long long y){
	long long ret=1;
	while(y){
		if(y&1){
			ret=ret*x%mod;
		}
		x=x*x%mod;
		y/=2;
	}
	return ret;
}
int a[200020];
int cnt,fa[200020],head[200020],mark[200020];
long long siz[200020];

void add(int x,int y){
	edge[cnt].next=head[x];
	edge[cnt].num=y;
	head[x]=cnt++;
	edge[cnt].next=head[y];
	edge[cnt].num=x;
	head[y]=cnt++;
}
int f[200020];
int find(int x){
	if(f[x]==x) return x;
	else return f[x]=find(f[x]);
}
long long all[200020];
long long allsum=0;
void dfs(int x){
	int fax=find(x);
	long long tmp=all[fax]*myget(1ll*a[x],mod-2)%mod;
	ans=ans+(allsum-all[fax]+mod)%mod*x%mod;
	ans%=mod;
	siz[x]=a[x];
	mark[x]=tim++;
	fa[x]=mark[x];
	for(int i=head[x];i!=-1;i=edge[i].next){
		int v=edge[i].num;
		if(mark[v]){
			if(fa[x]==-1) fa[x]=mark[v];
			else fa[x]=min(fa[x],mark[v]);
			continue;
		}
		dfs(v);
		if(fa[v]>=mark[x]){
			ans=ans+siz[v]*x%mod;
			tmp=tmp*myget(1ll*siz[v],mod-2)%mod;
			ans%=mod;
		}
		siz[x]*=siz[v];
		siz[x]%=mod;
		fa[x]=min(fa[x],fa[v]);
	}
	if(x==fax&&tmp==1ll) return;
	ans=ans+tmp*x%mod;
	ans%=mod;
}

int main(){
	int T,n,m,x,y;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			f[i]=i;
		}
		memset(head,-1,sizeof(head));
		cnt=0;
		allsum=0;
		for(int i=0;i<m;i++){
			scanf("%d%d",&x,&y);
			add(x,y);
			int fax=find(x);
			int fay=find(y);
			if(fax==fay);
			else f[fax]=fay;
		}
		for(int i=1;i<=n;i++)
			if(f[i]==i) all[i]=1;
		for(int i=1;i<=n;i++){
			int fax=find(i);
			all[fax]=all[fax]*a[i]%mod;
		}
		for(int i=1;i<=n;i++)
			if(f[i]==i) allsum=(allsum+all[i])%mod;
		ans=0;
		tim=1;
		ans=0;
		memset(mark,0,sizeof(mark));
		for(int i=1;i<=n;i++)
			if(f[i]==i) dfs(i);
		printf("%lld\n",ans);
	}
}
