#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
struct Node{
	int x,y,xx,ty;
}a[200010],x,y;
long long t[800010];
int b[200010],l1,n,lz[2000010];
int cn,cnt;
bool cmp(Node a ,Node b){
	if(a.y==b.y)return a.ty>b.ty;
	return a.y<b.y;
}
int _hash(int x){
	return lower_bound(b+1,b+1+l1,x)-b;
}

void build(){
	memset(t,0,sizeof(t));
}

void add(int x,int l,int r,int rt,int k){
	if(l==r){
		t[rt]+=k;
		return;
	}
	int ls=rt<<1,rs=ls|1,mid=l+r>>1;
	if(x<=mid) add(x,l,mid,ls,k);
		else add(x,mid+1,r,rs,k);
	t[rt]=t[ls]+t[rs];
}

long long query(int x,int y,int l,int r,int rt){
	if(x==l&&y==r){
		return t[rt];
	}
	long long ret=0;
	int ls=rt<<1,rs=ls|1,mid=l+r>>1;
	if(y<=mid){
		ret+=query(x,y,l,mid,ls);
	}
	else{
		if(x>mid){
			ret+=query(x,y,mid+1,r,rs);
		}
		else{
			ret+=query(x,mid,l,mid,ls);
			ret+=query(mid+1,y,mid+1,r,rs);
		}
	}
	return ret;
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		cn=0,cnt=0;
		for(int i=0;i<n;i++){
			scanf("%d%d",&x.x,&x.y);
			scanf("%d%d",&y.x,&y.y);
			if(x.x==y.x){
				if(x.y>y.y){
					swap(x.y,y.y);
				}
				a[cnt].x=x.x;
				a[cnt].y=x.y;
				a[cnt++].ty=1;
				a[cnt].x=y.x;
				a[cnt].y=y.y;
				a[cnt++].ty=-1;
				b[cn++]=x.x;
			}
			else{
				if(x.x>y.x)swap(x.x,y.x);
				b[cn++]=x.x;
				b[cn++]=y.x;
				a[cnt].x=x.x;
				a[cnt].y=x.y;
				a[cnt].xx=y.x;
				a[cnt++].ty=0;
			}
		}
		sort(a,a+cnt,cmp);
		sort(b+1,b+cn+1);
		l1=unique(b+1,b+cn+1)-b-1;
		long long ans=0;
		for(int i=0;i<cnt;i++){
			if(a[i].ty==0){
				ans+=query(_hash(a[i].x),_hash(a[i].xx),1,n,1);
			}
			else{
				add(_hash(a[i].x),1,n,1,a[i].ty);
			}
		}
		printf("%lld\n",ans);
	}
}
