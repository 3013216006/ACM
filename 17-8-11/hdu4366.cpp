#include <iostream>
#include <stdio.h>
#include <map>
#include <string.h>
#include <algorithm>
using namespace std;
struct Node{
	int num,next;
}edge[50020];
int head[50020],cnt;
int nw;
int f,x;

void add(int x,int y){
	edge[cnt].next=head[x];
	edge[cnt].num=y;
	head[x]=cnt++;
}

int tr[50010<<3];

void build(int rt,int l,int r){
	if(l==r){
		tr[rt]=-1;
		return;
	}
	int ls=rt<<1,rs=ls|1,mid=l+r>>1;
	build(ls,l,mid);
	build(rs,mid+1,r);
	tr[rt]=-1;
}

void add(int x,int y,int rt,int l,int r){
	if(l==r){
		tr[rt]=y;
		return;
	}
	int ls=rt<<1,rs=ls|1,mid=l+r>>1;
	if(x<=mid) add(x,y,ls,l,mid);
	else add(x,y,rs,mid+1,r);
	tr[rt]=max(tr[ls],tr[rs]);
}

int query(int L,int R,int rt,int l,int r){
	if(L==l&&r==R){
		return tr[rt];
	}
	int ls=rt<<1,rs=ls|1,mid=l+r>>1;
	if(R<=mid) return query(L,R,ls,l,mid);
	else if(L>mid) return query(L,R,rs,mid+1,r);
	else return max(query(L,mid,ls,l,mid),query(mid+1,R,rs,mid+1,r));
}

struct Node1{
	int v,x,y,id;
}a[50010];
int l[50010],r[50010],t[50010];
int ans[50010],n,m;
map<int,int> M;
bool cmp(Node1 a,Node1 b){
	if(a.x==b.x) return a.v<b.v;
	return a.x>b.x;
}
void dfs(int x){
	nw++;
	a[x].v=nw;
	t[x]=nw;
	l[x]=nw;
	for(int i=head[x];i!=-1;i=edge[i].next){
		int v=edge[i].num;
		dfs(v);
	}
	r[x]=nw;
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		M.clear();
		M[-1]=-1;
		cnt=0;
		memset(head,-1,sizeof(head));
		for(int i=1;i<n;i++){
			scanf("%d%d%d",&f,&a[i].y,&a[i].x);
			M[a[i].y]=i;	
			a[i].id=i;
			add(f,i);
		}
		nw=-1;
		dfs(0);
		//for(int i=1;i<n;i++)
			//cout << l[i]<< " " << r[i] << endl;
		sort(a+1,a+n,cmp);
//		build(1,n-1);
		memset(tr,-1,sizeof(tr));
		for(int i=1;i<n;i++){
			ans[a[i].id]=M[query(l[a[i].id],r[a[i].id],1,1,n-1)];
			add(t[a[i].id],a[i].y,1,1,n-1);
		}
		for(int i=0;i<m;i++){
			scanf("%d",&x);
			cout << ans[x] << endl;
		}
	}
}
