#include <iostream>
using namespace std;
struct Node{
	int v,next;
}edge[MAXN];
struct tNode{
	int mx,mn,op;
};
int n,cnt;

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
		if(fa==v) continue;
		dfs1(v,x,d+1);
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
		l=work(l):
	}
	if(r.op){
		r=work(r):
	}
	ret.mx=max(l.mx,r.mx);
	ret.mn=min(l.mn,r.mn);
	return ret;
}

void build(int rt,int l,int r){
	int mid= l+r>>1,ls = rt << 1, rs = ls|1;
	if(l==r){
		t[rt].mx=t[rt].mn=v[l];
		t[rt].op=0;
		return;
	}
	build(ls,l,mid);
	build(rs,mid+1,r);
	t[rt]=update(t[ls],t[rs]);
}

int query(int l,int r,int rt,int L,int R){
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
			return query(l,r,rs,mid+1,r);
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
	}
	if(x<=mid) changeone(x,v,ls,L,mid);
	else changeone(x,v,rs,mid+1,R);
	t[rt]=update(t[ls],t[rs]);
}

void changeop(int l,int r,int rt,int L,int R){
	if(l==L&&r==R){
		t[rt].op^=1;
		return;
	}
	int mid=L+R>>1,ls=rt<<1,rs=ls|1;
	if(t[rt].op){
		t[ls].op^=1;
		t[rs].op^=1;
	}
	if(r<=mid) 
		changeone(l,r,ls,L,mid);
	else	if(l>mid)
				changeone(l,r,rs,mid+1,r);
			else{
				changeone(l,mid,ls,L,mid);
				changeone(mid+1,r,rs,mid+1,R);
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
	if(dep[topfa[x]] < dep[topfa[y]])
		swap(x,y);
	if(topfa[x]==topfa[y]){
		if(x==y) return -1;
		if(dep[x]<dep[y]) return query(num[x]+1,num[y]);
		else return query(num[y]+1,num[x]);
	}
	return max(getmax(fa
}


int main(){
	int T;
	scanf("%d", &T);
	while(T--){
		scanf("%d", &n);
		for(int i = 1; i < n; i++){
			scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].v);
			add(a[i].x,a[i].y);
		}
		dfs1(1,0,1);
		dfs2(1,0,1);
		for(int i=1;i<n;i++){
			if(fa[a[i].x]==a[i].y);
			else swap(a[i].x,a[i].y);
			v[num[a[i].x]]=a[i].v;
		}
		build(1,1,n);
	}
}
