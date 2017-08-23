#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
struct Node{
	int v,next;
}edge[200010];
int head[200010];
struct Node1{
	int x,id,flag;
}v[330300];
int cnt;
void addedge(int x,int y){
	edge[cnt].next=head[x];
	edge[cnt].v=y;
	head[x]=cnt++;
	edge[cnt].next=head[y];
	edge[cnt].v=x;
	head[y]=cnt++;
}
bool cmp(Node1 a,Node1 b){
	if(a.x==b.x) return a.flag<b.flag;
	else return a.x<b.x;
}
int d[100100],siz[100100],son[100010],f[100100],topfa[100100],p[100100];
long long ans[100100],t[100100<<8];
int n,m;

void dfs1(int x,int fa,int dep){
	d[x]=dep;
	siz[x]=1;
	son[x]=-1;
	f[x]=fa;
	for(int i=head[x];i!=-1;i=edge[i].next){
		int v=edge[i].v;
		if(v==fa) continue;
		dfs1(v,x,dep+1);
		siz[x]+=siz[v];
		if(son[x]==-1||siz[son[x]]<siz[v]) son[x]=v;
	}
}

void dfs2(int x,int tf){
	p[x]=cnt++;
	topfa[x]=tf;
	if(son[x]!=-1){
		dfs2(son[x],tf);
	}
	for(int i=head[x];i!=-1;i=edge[i].next){
		int v=edge[i].v;
		if(v==f[x]||v==son[x]) continue;
		dfs2(v,v);
	}
}

void add(int x,int v,int rt,int l,int r){
	t[rt]+=v;
	if(l==r){
		return;
	}
	int mid=l+r>>1,ls=rt<<1,rs=ls|1;
	if(x<=mid) add(x,v,ls,l,mid);
	else add(x,v,rs,mid+1,r);
}

long long query_t(int L,int R,int rt,int l,int r){
	if (l==L&&R==r){
		return t[rt];
	}
	int mid=l+r>>1;
	int ls=rt<<1,rs=ls|1;
	if(R<=mid) return query_t(L,R,ls,l,mid);
	else if(L>mid) return query_t(L,R,rs,mid+1,r);
	else return query_t(L,mid,ls,l,mid)+query_t(mid+1,R,rs,mid+1,r);
}

long long query(int x,int y){
	if(d[topfa[x]]<d[topfa[y]]) swap(x,y);
	if(topfa[x]==topfa[y]){
		if(d[x]<d[y]);else swap(x,y);
		return query_t(p[x],p[y],1,1,n);
	}
	long long ret=query(y,f[topfa[x]])+query_t(p[topfa[x]],p[x],1,1,n);
	return ret;
}

int L[100100],R[100100];
void build(int rt,int l,int r){
	t[rt]=0;
	if(l==r) return;
	int mid=l+r>>1,ls=rt<<1,rs=ls|1;
	build(ls,l,mid);
	build(rs,mid+1,r);
}
int main(){
	int x,y;
	while(~scanf("%d%d",&n,&m)){
		for(int i=1;i<=n;i++){
			scanf("%d",&v[i].x);
			v[i].id=i;
			v[i].flag=0;
		}
		memset(head,-1,sizeof(int)*(n+1));
		cnt=0;
		for(int i=1;i<n;i++){
			scanf("%d%d",&x,&y);
			addedge(x,y);
		}
		cnt=n+1;
		for(int i=0;i<m;i++){
			scanf("%d%d",&L[i],&R[i]);
			scanf("%d%d",&x,&y);
			v[cnt].x=x;
			v[cnt].id=i;
			v[cnt].flag=-1;
			cnt++;
			v[cnt].x=y;
			v[cnt].id=i;
			v[cnt].flag=1;
			cnt++;
			ans[i]=0;
		}
		int l=cnt;
		sort(v+1,v+cnt,cmp);
		dfs1(1,0,1);
		cnt=1;
		dfs2(1,1);
		build(1,1,n);
		for(int i=0;i<l;i++){
			int r=v[i].id;
			if(v[i].flag){
				ans[r]+=v[i].flag*query(L[r],R[r]);
			}
			else{
				add(p[r],v[i].x,1,1,n);
			}
		}
		for(int i=0;i<m;i++){
			printf("%lld%c",ans[i]," \n"[i==m-1]);
		}
	}
}
