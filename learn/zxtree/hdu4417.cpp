#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
struct Node{
	int l,r,k;
}b[100100];
int a[100100],tr[100100<<5],ls[100100<<5],rs[100100<<5],c[100100<<3],mytr[100100];
int cnt;

int build(int l,int r){
	int nw=cnt++;
	if(l==r){
		tr[nw]=0;
		return nw;
	}
	int mid=l+r>>1;
	ls[nw]=build(l,mid);
	rs[nw]=build(mid+1,r);
	tr[nw]=tr[ls[nw]]+tr[rs[nw]];
	return nw;
}

int add(int x,int rt,int l,int r){
	int nw=cnt++;
	if(l==r){
		tr[nw]=tr[rt]+1;
		return nw;
	}
	int mid=l+r>>1;
	if(x<=mid) ls[nw]=add(x,ls[rt],l,mid),rs[nw]=rs[rt];
	else ls[nw]=ls[rt],rs[nw]=add(x,rs[rt],mid+1,r);
	tr[nw]=tr[ls[nw]]+tr[rs[nw]];
	return nw;
}

int query(int x,int rt,int l,int r){
	if(l==r){
		return tr[rt];
	}
	int mid=l+r>>1;
	if(x<=mid) return query(x,ls[rt],l,mid);
	else return query(x,rs[rt],mid+1,r)+tr[ls[rt]];
}

int main(){
	int T,cas=1,n,m;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		cnt=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			c[cnt++]=a[i];
		}
		for(int i=0;i<m;i++){
			scanf("%d%d%d",&b[i].l,&b[i].r,&b[i].k);
			b[i].l++;
			b[i].r++;
			c[cnt++]=b[i].k;
		}
		sort(c,c+cnt);
		int l=unique(c,c+cnt)-c;
		int t;
		cnt=0;
		mytr[0]=build(1,l);
		for(int i=1;i<=n;i++){
			t=lower_bound(c,c+l,a[i])-c+1;	
			mytr[i]=add(t,mytr[i-1],1,l);
		}
		printf("Case %d:\n",cas++);
		for(int i=0;i<m;i++){
			t=lower_bound(c,c+l,b[i].k)-c+1;
			int ans=query(t,mytr[b[i].r],1,l);
			ans-=query(t,mytr[b[i].l-1],1,l);
			printf("%d\n",ans);
		}
	}
}
