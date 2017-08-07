#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int t[35000<<3],f[35000<<3];
int ans[35010];

void build(int rt,int l,int r){
	int ls=rt<<1,rs=ls|1,mid=l+r>>1;
	if(l==r){
		t[rt]=ans[l-1];
		f[rt]=0;
		return;
	}
	build(ls,l,mid);
	build(rs,mid+1,r);
	t[rt]=max(t[ls],t[rs]);
	f[rt]=0;
}

void add(int L,int R,int rt,int l,int r){
	if(L==l&&R==r){
		t[rt]++;
		f[rt]++;
		return;
	}
	int ls=rt<<1,rs=ls|1,mid=l+r>>1;
	if(f[rt]){
		t[ls]+=f[rt];
		t[rs]+=f[rt];
		f[ls]+=f[rt];
		f[rs]+=f[rt];
		f[rt]=0;
	}
	if(R<=mid) add(L,R,ls,l,mid);
	else if(L>mid) add(L,R,rs,mid+1,r);
	else add(L,mid,ls,l,mid),add(mid+1,R,rs,mid+1,r);
	t[rt]=max(t[ls],t[rs]);
}

int query(int x,int rt,int l,int r){
	if(r==x) return t[rt];
	int mid=l+r>>1,ls=rt<<1,rs=ls|1;
	if(f[rt]){
		t[ls]+=f[rt];
		t[rs]+=f[rt];
		f[ls]+=f[rt];
		f[rs]+=f[rt];
		f[rt]=0;
	}
	if(x<=mid) return query(x,ls,l,mid);
	else return max(t[ls],query(x,rs,mid+1,r));
}
int vis[35010],a[35010],pre[35010];
int main(){
	int n,k;
	while(~scanf("%d%d",&n,&k)){
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			pre[i]=vis[a[i]]+1;
			vis[a[i]]=i;
		}
		memset(ans,0,sizeof(ans));
		for(int i=1;i<=k;i++){
			build(1,1,n);
			for(int j=1;j<=n;j++){
				add(pre[j],j,1,1,n);
				ans[j]=query(j,1,1,n);
			}
		}
		cout << ans[n] << endl;
	}
}
