#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
struct Node{
	int x,y;
}a[400001];
int vis[200001];
bool cmp(Node a,Node b){
	if(a.x==b.x)
		return a.y>b.y;
	else return a.x<b.x;
}
int main(){
	int n,k,q;
	while(~scanf("%d%d%d",&n,&k,&q)){
		int r=0;
		for(int i=0;i<n;i++){
			scanf("%d",&a[i*2].x);
			a[i*2].y=1;
			scanf("%d",&a[i*2+1].x);
			a[i*2+1].y=-1;
			r=max(r,a[i*2+1].x);
		}
		n*=2;
		sort(a,a+n,cmp);
		memset(vis,0,sizeof(vis));
		int l=0,t=0;
		for(int i=1;i<=r;i++){
			while(a[l].x==i&&a[l].y==1)
				t++,l++;
			vis[i]=vis[i-1];
			if(t>=k) vis[i]++;
			while(l<n&&a[l].x==i) t--,l++;
		}
		int x,y;
		for(int i=0;i<q;i++){
			scanf("%d%d",&x,&y);
			if(x<=r&&y>r) y=r;
			printf("%d\n",vis[y]-vis[x-1]);
		}
	}
}
