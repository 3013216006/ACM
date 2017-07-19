#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
struct Node{
	int max,l,r,sum;
}t[MAXN<<2];
int a[]
void pushup(int rt){
	int ls=rt<<1,rs=ls|1;
	t[rt].sum=t[ls].sum+t[rs].sum;
	t[rt].max=max(t[ls].max,t[rs].max);
	t[rt].max=max(t[rt].max,t[ls].r+t[rt].l);
	t[rt].l=max(t[ls].l,t[ls].sum+t[rs].l);
	t[rt].r=max(t[rs].r,t[rs].sum+t[ls].r);
}

void build(int l,int r,int rt){
	if(l==r){
		t[rt].max=a[l];
		t[rt].sum=a[l];
		t[rt].l=t[rt].r=a[l];
		return;
	}
	int mid=l+r>>1,ls=rt<<1,rs=ls|1;
	build(l,mid,ls);
	build(mid+1,r,rs);
	pushup(rt);
}

Node query(int x,int y,int l,int r,int rt){
	if(x==l&&y==r){
		return t[rt];
	}
	int mid=l+r>>1,ls=rt<<1,rs=ls|1;
	if(x<=mid){
		if(y<=mid){
			return query(x,y,l,mid,ls);	
		}
		else{
			Node left=query(x,mid,l,mid,ls);
			Node right=query(mid+1,y,mid+1,r,rs);
			Node ret;
			ret.sum=left.sum+right.sum;
			ret.l=max(left.l,left.sum+right.l);
			ret.r=max(right.r,right.sum+left.r);
			ret.max=max(left.max,rifht.max);
			ret.max=max(ret.max,left.r+right.l);
			return ret;
		}
	}
	else{
		return query(x,y,mid+1,r,rs);
	}
}

int main(){
	int n;
	while(~scanf("%d",&n)){
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		build(1,n,1);
		scanf("%d",&m);
		while(m--){
			scanf("%d%d",&x,&y);
			Node tmp=query(x,y,1,n,1);
			printf("%d\n",tmp.max);
		}
	}
}
