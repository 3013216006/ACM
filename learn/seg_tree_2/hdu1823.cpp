#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
double tr[100<<2][1000<<2];

void _build(int x,int rt,int l,int r){
	if(l==r){
		tr[x][rt]=-1;
		return;
	}
	int mid=l+r>>1,ls=rt<<1,rs=ls|1;
	_build(x,ls,l,mid);
	_build(x,rs,mid+1,r);
}

void build(int rt,int l,int r,int l1,int r1){
	_build(rt,1,l1,r1);
	if(l==r) return;
	int mid=l+r>>1,ls=rt<<1,rs=ls|1;
	build(ls,l,mid,l1,r1);
	build(rs,mid+1,r,l1,r1);
}

void _add(int x,int y,double v,int rt,int l,int r){
	if(l==r){
		tr[x][rt]=v;
		return;
	}
	int mid=l+r>>1,ls=rt<<1,rs=ls|1;
	if(y<=mid) _add(x,y,v,ls,l,mid);
	else _add(x,y,v,rs,mid+1,r);
	tr[x][rt]=max(tr[x][ls],tr[x][rs]);
}

void add(int x,int y,double v,int rt,int l,int r){
	_add(rt,y,v,1,0,1000);
	if(l==r) return;
	int mid=l+r>>1,ls=rt<<1,rs=ls|1;
	if(x<=mid) add(x,y,v,ls,l,mid);
	else add(x,y,v,rs,mid+1,r);
}

double _query(int x,int L,int R,int rt,int l,int r){
	if(L==l&&r==R){
		return tr[x][rt];
	}
	int mid=l+r>>1,ls=rt<<1,rs=ls|1;
	if(R<=mid) return _query(x,L,R,ls,l,mid);
	else if(L>mid) return _query(x,L,R,rs,mid+1,r);
	return max(_query(x,L,mid,ls,l,mid),_query(x,mid+1,R,rs,mid+1,r));
}

double query(int L,int R,int L1,int R1,int rt,int l,int r){
	if(L==l&&R==r){
		return _query(rt,L1,R1,1,0,1000);
	}
	int mid=l+r>>1,ls=rt<<1,rs=ls|1;
	if(R<=mid) return query(L,R,L1,R1,ls,l,mid);
	else if(L>mid) return query(L,R,L1,R1,rs,mid+1,r);
	else return max(query(L,mid,L1,R1,ls,l,mid),query(mid+1,r,L1,R1,rs,mid+1,r));
}
char s[10];

int main(){
	int n;
	int x,x1;
	double y,z;
	while(scanf("%d",&n),n){
		build(1,0,100,0,1000);
		for(int i=0;i<n;i++){
			scanf("%s",s);
			if(s[0]=='I'){
				scanf("%d%lf%lf",&x,&y,&z);
				int tp=(int) y*10;
				add(x-100,tp,z,1,0,100);
			}
			else{
				scanf("%d%d%lf%lf",&x,&x1,&y,&z);
				int tp1=(int) (y*10),tp2=(int) (z*10);
				if(x>x1) swap(x,x1);
				if(tp1>tp2) swap(tp1,tp2);
				double ans=query(x-100,x1-100,tp1,tp2,1,1,100);
				if(ans<0) puts("-1");
				else printf("%.1f\n",ans);
			}
		}
	}
}
