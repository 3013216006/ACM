#include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>
using namespace std;
struct Node{
	int x,y;
}a[500100];

bool cmp(Node a,Node b){
	if(a.y==b.y) return a.x<b.x;
	return a.y<b.y;
}
int vis[50010];
int main(){
	int n;
	while(~scanf("%d",&n)){
		if(n==0) break;
		for(int i=0;i<n;i++)
			scanf("%d%d",&a[i].x,&a[i].y);
		sort(a,a+n,cmp);
		memset(vis,0,sizeof(vis));
		int s=0;
		//vis[a[0].x]=a[0].y;
		int l=0
		int flag=1;
		for(int i=1;i<n&&flag;i++){
			if(a[i].y!=a[i-1].y){
				for(int j=l;j<i;j++)
					add(a[j].x,a[j].y);
				l=i;
				continue;
			}
			if(vis[a[i].y]==s) vis[a[i].y]++;
				else flag=0;
		}
		if(flag) puts("YES");
			else puts("NO");
	}
}
