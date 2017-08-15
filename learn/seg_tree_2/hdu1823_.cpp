#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
struct Node{
	int l,r;
	double v;
}t[100<<2],tr[100<<2][1000<<2];

void _build(int x,int rt,int l,int r){
	tr[x][rt].l=l;
	tr[x][rt].r=r;
	tr[x][rt].v=-1;
	if(l==r){
		return ;
	}

	int mid=l+r>>1,ls=rt<<1,rs=ls|1;
	_build(x,ls,l,mid);
	_build(x,rs,mid+1,r);
}

void build(int rt,int l,int r){
	t[rt].l=l;t[rt].r=r;
	_build(rt,1,0,1000);
	if(l==r){
		return ;
	}
	int ls=rt<<1,rs=ls|1,mid=l+r>>1;
	build(ls,l,mid);
	build(rs,mid+1,r);
}

void _add(int x,int rt,int y,double v){
	////cout << "_add" << x << " " << rt << " " << y << " " << v << endl;
	//cout << tr[x][rt].l << " " << tr[x][rt].r << endl;
	if(tr[x][rt].l==tr[x][rt].r){
		tr[x][rt].v=max(tr[x][rt].v,v);
		return;
	}
	int mid=tr[x][rt].l+tr[x][rt].r>>1;
	int ls=rt<<1,rs=ls|1;
	if(y<=mid) _add(x,ls,y,v);
	else _add(x,rs,y,v);
	tr[x][rt].v=max(tr[x][ls].v,tr[x][rs].v);
}

void add(int rt,int x,int y,double v){
	int mid=t[rt].l+t[rt].r>>1;
	_add(rt,1,y,v);
	if(t[rt].l==t[rt].r) return ;
	int ls=rt<<1,rs=ls|1;
	if(x<=mid) add(ls,x,y,v);
	else add(rs,x,y,v);
}

double _query(int x,int rt,int l,int r){
	//cout << "_query" << x << " " << rt << "  " << l << " " << r << endl;
	double ret;
	if(tr[x][rt].l==l&&tr[x][rt].r==r){
		ret=tr[x][rt].v;
	}
	else{
	int mid=tr[x][rt].l+tr[x][rt].r>>1;
	int ls=rt<<1,rs=ls|1;
	if(r<=mid) ret=_query(x,ls,l,r);
	else if(l>mid) ret=_query(x,rs,l,r);
	else ret=max(_query(x,ls,l,mid),_query(x,rs,mid+1,r));
	}
	//cout << "_query" << x << " " << rt << "  " << l << " " << r << endl;
	//cout << ret << endl;
	return ret;
}

double query(int rt,int l,int r,int L1,int R1){
	//cout << "query" << rt << " " << l << " " << r << endl;
	//cout << L1 << " " << R1 << endl;
	if(t[rt].l==l&&t[rt].r==r){
		return _query(rt,1,L1,R1);
	}
	int mid=t[rt].l+t[rt].r>>1;
	//cout << mid << endl;
	int ls=rt<<1,rs=ls|1;
	if(r<=mid) return query(ls,l,r,L1,R1);
	else if(l>mid) return query(rs,l,r,L1,R1);
	else return max(query(ls,l,mid,L1,R1),query(rs,mid+1,r,L1,R1));
}

char s[10];
int x,x1;
double y,z;

int main(){
	int n;
	while(~scanf("%d",&n),n){
		build(1,0,100);
		for(int i=0;i<n;i++){
			scanf("%s",s);
			if(s[0]=='I'){
				scanf("%d%lf%lf",&x,&y,&z);
				x-=100;
				int tp=(int) (y*10);
				add(1,x,tp,z);
			}
			else{
				scanf("%d%d%lf%lf",&x,&x1,&y,&z);
				x-=100;
				x1-=100;
				int tp1=(int) (y*10);
				int tp2=(int) (z*10);
				if(x>x1) swap(x,x1);
				if(tp1>tp2) swap(tp1,tp2);
				double ans = query(1,x,x1,tp1,tp2);
				if(ans<0) puts("-1");
				else printf("%.1f\n",ans);
			}
		}
	}
}
