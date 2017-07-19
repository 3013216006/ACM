#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
struct Node{
	int x,y;
}a[1000010];
long long sum[4000010],f[4000010],sav[1000010];
bool cmp1(Node a,Node b){
	return a.y>b.y;
}

bool cmp2(Node a,Node b){
	return a.x>b.x;
}
long long mod=1000000007ll;
long long getans(int xx,int k){
	long long ret=1,x=xx;
	while(k){
		if(k&1){
			ret*=x;
			ret%=mod;
		}
		x=x*x%mod;
		k>>=1;
	}
	return ret;
}

void build(int l,int r,int rt){
	int mid=l+r>>1,ls=rt<<1,rs=ls|1;
	sum[rt]=0;
	f[rt]=1;
	if(l==r) return;
	build(l,mid,ls);
	build(mid+1,r,rs);
}

void pushdown(int rt){
	int ls=rt<<1,rs=ls|1;
	f[ls]*=f[rt];f[ls]%=mod;
	f[rs]*=f[rt];f[rs]%=mod;
	sum[ls]=sum[ls]*f[rt]%mod;
	sum[rs]=sum[rs]*f[rt]%mod;
	f[rt]=1;
}

void add(int x,int l,int r,int rt,long long k){
//	cout << x << " " << l << " " << r << " " << k << endl;
	if(l==r){
		sum[rt]=k;
		f[rt]=1;
		return ;
	}
	if(f[rt]!=1) pushdown(rt);
	int mid=l+r>>1,ls=rt<<1,rs=ls|1;
	if(x<=mid) add(x,l,mid,ls,k);
	else add(x,mid+1,r,rs,k);
	sum[rt]=(sum[ls]+sum[rs])%mod;
}

void change(int x,int y,int l,int r,int rt,long long k){
	if(x==l&&y==r){
		sum[rt]=sum[rt]*k%mod;
		f[rt]=f[rt]*k%mod;
		return ;
	}
	if(f[rt]!=1) pushdown(rt);
	int mid=l+r>>1,ls=rt<<1,rs=ls|1;
	if(y<=mid){
		change(x,y,l,mid,ls,k);
	}
	else if(x>mid){
		change(x,y,mid+1,r,rs,k);
	}
	else{
		change(x,mid,l,mid,ls,k);
		change(mid+1,y,mid+1,r,rs,k);
	}
	sum[rt]=(sum[ls]+sum[rs])%mod;
}

long long query(int x,int y,int l,int r,int rt){
//	cout << x  << " " << y << " " << l << " " << r << " " << rt << endl;
	if(x==l&&r==y){
		return sum[rt];
	}
	if(f[rt]!=1) pushdown(rt);
	int mid=l+r>>1,ls=rt<<1,rs=ls|1;
	if(y<=mid) return query(x,y,l,mid,ls);
		else if(x>mid) return query(x,y,mid+1,r,rs);
			else return (query(x,mid,l,mid,ls)+query(mid+1,y,mid+1,r,rs))%mod;
}

int main(){
	int T,n;
	while(~scanf("%d",&n)){
		for(int i=0;i<n;i++)
			scanf("%d%d",&a[i].x,&a[i].y);
		build(1,n,1);
	//	cout << "hahai" << endl;
		sort(a,a+n,cmp1);
		for(int i=0;i<n;i++){
		//	cout << getans(3,a[i].y) << " " << getans(2,n-i-1) << endl;
			sav[i+1]=getans(3,a[i].y)*getans(2,n-i-1)%mod;
			add(i+1,1,n,1,sav[i+1]);
			a[i].y=i+1;
		}
		sort(a,a+n,cmp2);
		long long ans=0;
		long long haha=getans(2,mod-2);
	//	cout << "haha" << endl;
		for(int i=0;i<n;i++){
			long long tmp=0;
			if(a[i].y>1) tmp=query(1,a[i].y-1,1,n,1);
			ans+=getans(2,a[i].x)*(((tmp*haha)%mod+query(a[i].y,a[i].y,1,n,1))%mod)%mod;
			ans%=mod;
			add(a[i].y,1,n,1,0);
			if(a[i].y>1)
			change(1,a[i].y-1,1,n,1,haha);
		}
		printf("%lld\n",ans);
	}
}
