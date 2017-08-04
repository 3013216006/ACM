#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>
using namespace std;
int t[50010],a[50010];

int lowbit(int x){
	return x&(-x);
}
int n,m;
void add(int x,int v){
	while(x<=n){
		t[x]=max(t[x],v);
		x+=lowbit(x);
	}
}

int query(int x){
	int ret=0;
	while(x){
		ret=max(t[x],ret);
		x-=lowbit(x);
	}
	return ret;
}

int main(){
	while(~scanf("%d%d",&n,&m)){
		int mx=0;
		int x;
		memset(t,0,sizeof(t));
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			add(i,a[i]);
			mx=max(mx,a[i]);
		}
		for(int i=1;i<=m;i++){
			scanf("%d",&x);
			if(mx<x||x<=a[1]) continue;
			int l=1,r=n,ans=n-1;
			while(l<=r){
				int mid=l+r>>1;
				if(query(mid)<x) ans=mid,l=mid+1;
				else r=mid-1;
			}
			a[ans]++;
			add(ans,a[ans]);
		}
		for(int i=1;i<=n;i++){
			printf("%d\n",a[i]);
		}
	}
}
