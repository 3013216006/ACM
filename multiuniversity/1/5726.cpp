#include <iostream>
#include <stdio.h>
#include <queue>
#include <map>
#define MAXN 100010
using namespace std;
struct Node{
	int x,l;
};
int a[MAXN];
int gcd(int x,int y){
	if(y==0) return x;
	return gcd(y,x%y);
}
map<int,long long>M;
queue<Node> Q[2];
int t[MAXN*5];
void build(int l,int r,int rt){
	if(l==r){
		t[rt]=a[l-1];
		return;
	}
	int mid=l+r>>1,ls=rt<<1,rs=ls|1;
	build(l,mid,ls);
	build(mid+1,r,rs);
	t[rt]=gcd(t[ls],t[rs]);
}

int query(int x,int y,int l,int r,int rt){
	if(x==l&&y==r){
		return t[rt];
	}
	int mid=l+r>>1,ls=rt<<1,rs=ls|1;
	if(x<=mid){
		if(y<=mid){
			return query(x,y,l,mid,ls);
		}
		else{
			return gcd(query(x,mid,l,mid,ls),query(mid+1,y,mid+1,r,rs));
		}
	}
	else{
		return query(x,y,mid+1,r,rs);
	}
}

int main(){
	int T,n,m,x,y,cas=1;
	scanf("%d",&T);
	while(T--){
		M.clear();
		scanf("%d",&n);
		while(!Q[1].empty()) Q[1].pop();
		while(!Q[0].empty()) Q[0].pop();
		Node tmp;
		int l=1,r=0;
		for(int i=0;i<n;i++,l^=1,r^=1){
			scanf("%d",&a[i]);
			tmp.x=a[i];
			tmp.l=i;
			int rt=i+1;
			while(!Q[r].empty()){
				Node t=Q[r].front();
				Q[r].pop();
				if(tmp.x==t.x){
					tmp.l=t.l;
				}
				else{
					M[tmp.x]+=rt-tmp.l;
					rt=tmp.l;
					Q[l].push(tmp);
					t.x=gcd(t.x,tmp.x);
					tmp=t;
				}
			}
				M[tmp.x]+=rt-tmp.l;
				Q[l].push(tmp);
		}
		build(1,n,1);
		printf("Case #%d:\n",cas++);
		int m;
		scanf("%d",&m);
		while(m--){
			scanf("%d%d",&x,&y);
			int ans=query(x,y,1,n,1);
			printf("%d %I64d\n",ans,M[ans]);
		}
	}
}
