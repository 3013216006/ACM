#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
int vis[100000];
int main(){
	int p,a,b;
	scanf("%d",&p);
	int cas=1;
	memset(vis,0,sizeof(vis));
	while(scanf("%d",&a)!=EOF && a){
		scanf("%d",&b);
		a%=p;
		b%=p;
		int ans=1,t=1;
		if(b==0){
			if(a==0) puts("1");
				else puts("0");
				continue;
		}
		for(int i=1;i<p;i++){
			t*=a;
			t%=p;
			if(t==b) break;
			if(vis[t]==cas) break;
			vis[t]=cas;
			ans++;
		}
		cas++;
		if(t==b) printf("%d\n",ans);
			else puts("0");
	}
}
