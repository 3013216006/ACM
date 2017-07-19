#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
struct Node{
	int x,y;
}a[200200];
int b[100100];
bool cmp(Node a,Node b){
	if(a.x==b.x)
		return a.y<b.y;
	return a.x<b.x;
}
int abs(int x){
	if(x<0) return -x;
	return x;
}
int main(){
	int n,m;
	while(~scanf("%d%d",&n,&m)){
		for(int i=0;i<n;i++){
			scanf("%d",&a[i].x);
			a[i].y=0;
		}
		for(int i=0;i<m;i++){
			scanf("%d",&b[i]);
			if(i){
				a[n].x=(b[i]+b[i-1])/2;
				if(b[i]+b[i-1]<0) a[n].x=(b[i]+b[i-1]-1)/2;
				a[n++].y=1;
			}
		}
		sort(a,a+n,cmp);
		int l=0,ans=0;
		for(int i=0;i<n;i++)
		if(a[i].y){
			l++;
		}
		else{
			ans=max(ans,abs(a[i].x-b[l]));
		}
		printf("%d\n",ans);
	}
}
