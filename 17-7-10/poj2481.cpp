#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
struct Node{
	int l,r,id;
}a[100080];
int sum[100080];
int t[100080];
int N;
int lowbit(int x){
	return x&(-x);
}
void add(int x,int op){
	while(x<=N){
		t[x]+=op;
		x+=lowbit(x);
	}
}
int query(int x){
	int ret=0;
	while(x){
		ret+=t[x];
		x-=lowbit(x);
	}
	return ret;
}
bool cmp(Node a,Node b){
	if(a.l==b.l) return a.r>b.r;
	else return a.l<b.l;
}
int ans[100010];
int main(){
	int n;
	while(~scanf("%d",&n)){
		if(n==0) break;
		N=0;
		for(int i=0;i<n;i++){
			scanf("%d%d",&a[i].l,&a[i].r);
			a[i].l++;
			a[i].r++;
			a[i].id=i;
			N=max(N,a[i].r);
		}
		memset(ans,0,sizeof(ans));
		memset(t,0,sizeof(t));
		sort(a,a+n,cmp);
		a[n].l=-1;
		sum[0]=0;
		for(int i=1;i<n;i++)
			if(a[i].l==a[i-1].l&&a[i].r==a[i-1].r) sum[i]=sum[i-1]+1;
			else sum[i]=0;
		for(int i=0;i<n;i++){
			ans[a[i].id]=i-query(a[i].r-1);
			ans[a[i].id]-=sum[i];
			add(a[i].r,1);
		}
		for(int i=0;i<n-1;i++)
			printf("%d ",ans[i]);
		printf("%d\n",ans[n-1]);
	}
}
