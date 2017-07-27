#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
struct Node{
	int x,y;
}a[110];
bool cmp(Node a,Node b){
	return a.x<b.x;
}
int b[110];
int main(){
	int n,w;
	while(~scanf("%d%d",&n,&w)){
		for(int i=0;i<n;i++){
			scanf("%d",&a[i].x);
			a[i].y=i;
		}
		sort(a,a+n,cmp);
		for(int i=0;i<n;i++){
			b[i]=(a[i].x+1)/2;
			w-=b[i];
		}
		if(w<0){
			puts("-1");
			continue;
		}
		for(int i=n-1;i>=0;i--){
			int x=min(a[i].x-b[i],w);
			w-=x;
			b[i]+=x;
			if(w==0) break;
		}
		for(int i=0;i<n;i++)
			a[a[i].y].x=b[i];
			int flag=0;
		for(int i=0;i<n;i++){
			if(flag) printf(" ");
			flag=1;
			printf("%d",a[i].x);
		}
		puts("");
		
	}
}
