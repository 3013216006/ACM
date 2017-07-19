#include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>
using namespace std;
struct Node{
	int x,y;
}a[200020];
int t[800100],b[200100];
void build(int l,int r,int root){
	memset(t,0,sizeof(t));
}
void updata(int x,int y,int k,int l,int r,int rt){
	if(x==l&&y==r){
		t[rt]=k;
		return;
	}
	int mid=l+r>>1,ls=rt<<1,rs=ls+1;
	if(t[rt]) t[ls]=t[rt],t[rs]=t[rt],t[rt]=0;
	if(y<=mid) updata(x,y,k,l,mid,ls);
		else if(x>mid) updata(x,y,k,mid+1,r,rs);
			else{
				updata(x,mid,k,l,mid,ls);
				updata(mid+1,y,k,mid+1,r,rs);
			}
}
int tquery(int x,int l,int r,int rt){
	if(t[rt]) return t[rt];
	if(l==r) return t[rt];
	int mid=l+r>>1,ls=rt<<1,rs=ls+1;
	if(x<=mid) return tquery(x,l,mid,ls);
		return tquery(x,mid+1,r,rs);
}

int lowbit(int x){
	return x&(-x);
}
int n,m;
void add(int x,int k){
	while(x<=m){
		b[x]+=k;
		x+=lowbit(x);
	}
}

int query(int x){
	int ret=0;
	while(x){
		ret+=b[x];
		x-=lowbit(x);
	}
	return ret;
}
int v[200010];
int main(){
	while(~scanf("%d%d",&n,&m)){
		for(int i=1;i<n;i++)
			scanf("%d",&v[i]);
		for(int i=1;i<=m;i++){
			scanf("%d%d",&a[i].x,&a[i].y);
			if(a[i].x>a[i].y) swap(a[i].x,a[i].y);
		}
		n--;
		build(1,n,1);
		memset(b,0,sizeof(b));
		for(int i=m;i>=1;i--){
			updata(a[i].x,a[i].y-1,i,1,n,1);
		}
		for(int i=1;i<=n;i++){
			int x=tquery(i,1,n,1);
			if(x)
			add(x,v[i]);
		}
		build(1,n,1);
		for(int i=1;i<=m;i++){
			updata(a[i].x,a[i].y-1,i,1,n,1);
		}
		for(int i=1;i<=n;i++){
			int x=tquery(i,1,n,1);
			if(x)
			add(x+1,-v[i]);
		}
		for(int i=1;i<=m;i++){
			printf("%d\n",query(i));
		}
	}
}
