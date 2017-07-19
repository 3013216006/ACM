#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
struct Node{
	int x,y;
}a[100010];
int b[300010];
int abs(int x){
	if(x<0) return -x;
	return x;
}

int geta(Node a,Node b){
	int x=abs(a.x-b.x);
	int y=abs(a.y-b.y);
	return x+y;
}
int main(){
	int T,n,m;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++){
			scanf("%d%d",&a[i].x,&a[i].y);
		}
		if(((long long)n)*(n-1)/2>=m){
			puts("YES");
			continue;
		}
		memset(b,0,sizeof(b));
		int flag=1;
		for(int i=0;i<n&&flag;i++)
			for(int j=i+1;j<n&&flag;j++){
				int d=geta(a[i],a[j]);
				
				if(b[d]==1) flag=0;
				b[d]++;
			}
		if(flag) puts("NO");
		else puts("YES");
	}
}
