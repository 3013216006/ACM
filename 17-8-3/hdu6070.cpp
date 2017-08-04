#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;
double t[240000];
int fl[240000];


void build(int rt,int l,int r,double x){
	int ls=rt<<1,rs=ls|1,mid=l+r>>1;
	if(l==r){
		t[rt]=l*x;
		fl[rt]=0;
		return ;
	}
	build(ls,l,mid,x);
	build(rs,mid+1,r,x);
	t[rt]=min(t[ls],t[rs]);
	fl[rt]=0;
}

void add(int L,int R,int rt,int l,int r){
	if(L==l&&R==r){
		t[rt]+=1;
		fl[rt]+=1;
		return;
	}
	int ls=rt<<1,rs=ls|1,mid=l+r>>1;
	if(fl[rt]){
		t[ls]+=fl[rt];
		t[rs]+=fl[rt];
		fl[ls]+=fl[rt];
		fl[rs]+=fl[rt];
		fl[rt]=0;
	}
	if(R<=mid) add(L,R,ls,l,mid);
	else if(L>mid) add(L,R,rs,mid+1,r);
	else add(L,mid,ls,l,mid),add(mid+1,R,rs,mid+1,r);
	t[rt]=min(t[ls],t[rs]);
}

double query(int L,int R,int rt,int l,int r){
	if(L==l&&R==r){
		return t[rt];
	}
	int ls=rt<<1,rs=ls|1,mid=l+r>>1;
	if(fl[rt]){
		t[ls]+=fl[rt];
		t[rs]+=fl[rt];
		fl[ls]+=fl[rt];
		fl[rs]+=fl[rt];
		fl[rt]=0;
	}
	if(R<=mid) return query(L,R,ls,l,mid);
	else if(mid<L) return query(L,R,rs,mid+1,r);
	else return min(query(L,mid,ls,l,mid),query(mid+1,R,rs,mid+1,r));
}
int a[60010],vis[60010];
int pre[60010];
int main(){
	int T;
	int n;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			pre[i]=vis[a[i]];
			vis[a[i]]=i;
		}
		double l=0,r=1;
		while(r-l>1e-6){
			double mid=(l+r)/2;
			build(1,1,n,mid);
//			for(int j=0;j<=15;j++) 
//				cout << t[j] << endl;
			double tmp=mid;
			int flag=1;
			for(int i=1;i<=n&&flag;i++){
				tmp+=mid;
//				cout << pre[i] << " " << i << endl;
				add(pre[i]+1,i,1,1,n);
//					cout << i << ": " << query(1,i,1,1,n) << " " << tmp << endl;
				if(query(1,i,1,1,n)<tmp+1e-8) flag=0;
			}
			if(flag) l=mid;
			else r=mid;
		}
		printf("%.8f\n",l);
	}
}
