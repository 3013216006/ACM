#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#define MAXN 100000
using namespace std;
struct Node{
	int v,next;
}edge[MAXN];
struct tNode{
	int mx,mn,op;
}t[100000];
struct P{
	int x,y,v;
}a[MAXN];
int n,cnt,nu;
int size[MAXN],fa[MAXN],dep[MAXN],son[MAXN],topfa[MAXN],
	num[MAXN],v[MAXN],head[MAXN];
void add(int x,int y){
	edge[cnt].next=head[x];
	edge[cnt].v=y;
	head[x]=cnt++;
	edge[cnt].next=head[y];
	edge[cnt].v=x;
	head[y]=cnt++;
}

void dfs1(int x,int f,int d){
	dep[x]=d;
	fa[x]=f;
	size[x]=1;
	son[x]=-1;
	for(int i=head[x];i!=-1;i=edge[i].next){
		int v=edge[i].v;
		if(f==v) continue;
		dfs1(v,x,d+1);
		size[x]+=size[v];
		if(son[x]==-1||size[son[x]]<size[v]){
			son[x]=v;
		}
	}
}

void dfs2(int x,int fa,int tf){
	topfa[x]=tf;
	num[x]=nu++;
	if(son[x]!=-1){
		dfs2(son[x],x,tf);
	}
	for(int i=head[x];i!=-1;i=edge[i].next){
		int v=edge[i].v;
		if(v==fa||v==son[x]) continue;
		dfs2(v,x,v);
	}
}

tNode work(tNode a){
	swap(a.mx,a.mn);
	a.mx=-a.mx;
	a.mn=-a.mn;
	return a;
}

tNode update(tNode l,tNode r){
	tNode ret;
	ret.op=0;
	if(l.op){
		l=work(l);
	}
	if(r.op){
		r=work(r);
	}
	ret.mx=max(l.mx,r.mx);
	ret.mn=min(l.mn,r.mn);
	return ret;
}

void build(int rt,int l,int r){
	int mid= l+r>>1,ls = rt << 1, rs = ls|1;
	if(l==r){
	//	cout << l << " " << v[l] << endl;
		t[rt].mx=t[rt].mn=v[l];
		t[rt].op=0;
		return;
	}
	build(ls,l,mid);
	build(rs,mid+1,r);
	t[rt]=update(t[ls],t[rs]);
}

int query(int l,int r,int rt,int L,int R){
	//cout << l << " " << r << " " << rt << " " << L << " " << R << endl;
	//cout << t[rt].mx << " " << t[rt].mn << " " << t[rt].op << endl;
	if(l==L&&r==R){
		if(t[rt].op) return -t[rt].mn;
		else return t[rt].mx;
	}
	int mid=L+R>>1,ls=rt<<1,rs=ls|1;
	if(t[rt].op){
		t[ls].op^=1;
		t[rs].op^=1;
		t[rt].op=0;
		t[rt]=work(t[rt]);
	}
	if(r<=mid) 
		return query(l,r,ls,L,mid);
	else 
		if(l>mid) 
			return query(l,r,rs,mid+1,R);
		else{
			return max(query(l,mid,ls,L,mid),query(mid+1,r,rs,mid+1,R));	
		}
}

void changeone(int x,int v,int rt,int L,int R){
	if(L==R){
		t[rt].mx=t[rt].mn=v;
		t[rt].op=0;
		return;
	}
	int mid=L+R>>1,ls=rt<<1,rs=ls|1;
	if(t[rt].op){
		t[ls].op^=1;
		t[rs].op^=1;
		t[rt].op=0;
	}
	if(x<=mid) changeone(x,v,ls,L,mid);
	else changeone(x,v,rs,mid+1,R);
	t[rt]=update(t[ls],t[rs]);
}

void changeop(int l,int r,int rt,int L,int R){
	if(l==L&&r==R){
		//cout << l << endl;
		//cout << r << endl;
		t[rt].op^=1;
		return;
	}
	int mid=L+R>>1,ls=rt<<1,rs=ls|1;
	if(t[rt].op){
		t[ls].op^=1;
		t[rs].op^=1;
	}
	if(r<=mid) 
		changeop(l,r,ls,L,mid);
	else	if(l>mid)
				changeop(l,r,rs,mid+1,R);
			else{
				changeop(l,mid,ls,L,mid);
				changeop(mid+1,r,rs,mid+1,R);
			}
	t[rt]=update(t[ls],t[rs]);
}

void change(int x,int y){
	if(dep[topfa[x]] < dep[topfa[y]])
		swap(x,y);
	if(topfa[x]==topfa[y]){
		if(x==y) return;
		if(dep[x]>dep[y])
			changeop(num[y]+1,num[x],1,1,n);
		else 
			changeop(num[x]+1,num[y],1,1,n);
			return ;
	}
	change(fa[topfa[x]],y);
	changeop(num[topfa[x]],num[x],1,1,n);
}

int getmax(int x,int y){
	if(x==y) return -1000000000;
	//cout << "getmax " << x << " " << y << endl;
	if(dep[topfa[x]] < dep[topfa[y]])
		swap(x,y);
	if(topfa[x]==topfa[y]){
		//cout << "1*1" << endl;
		if(x==y) return -1;
		if(dep[x]<dep[y]) return query(num[x]+1,num[y],1,1,n);
		//cout << "haha" << endl;
		return query(num[y]+1,num[x],1,1,n);
	}
	//cout << "yes"  << endl;
	//cout << x << " " <<y << endl;
	//cout << topfa[x] << endl;
	return max(getmax(fa[topfa[x]],y),query(num[topfa[x]],num[x],1,1,n));
}
char s[100];

int main(){
	int T;
	int x,y;
	scanf("%d", &T);
	while(T--){
		scanf("%d", &n);
		memset(head, -1, sizeof(head));
		cnt=0;
		for(int i = 1; i < n; i++){
			scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].v);
			add(a[i].x,a[i].y);
		}
		nu=1;
		dfs1(1,0,1);
		dfs2(1,0,1);
		for(int i=1;i<n;i++){
			if(fa[a[i].x]==a[i].y);
			else swap(a[i].x,a[i].y);
			v[num[a[i].x]]=a[i].v;
			//cout << num[a[i].x] << " " << a[i].x << " " << a[i].v << endl;
		}
		for(int i=1;i<=n;i++){
			//cout << i << ":" << num[i] << endl;
			//cout << v[i] << endl;
		}
		v[1]=0;
		build(1,1,n);
		while(scanf("%s",s)){
			if(s[0]=='D') break;
			if(s[0]=='Q') {
				
				scanf("%d%d",&x,&y);
				printf("%d\n",getmax(x,y));

			}
			else if (s[0] == 'C') {
				scanf("%d%d",&x,&y);
				changeone(num[a[x].x],y,1,1,n);
			}
			else {
				//cout << 2 << endl;
				scanf("%d%d",&x,&y);
				change(x,y);
			}
		}
	}
}
