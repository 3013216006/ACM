#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int l[100100],r[100100];
int main(){
	int n,m,x,y;
	while(~scanf("%d%d",&n,&m)){
		int l1=n,r1=n;
		memset(l,0,sizeof(l));
		memset(r,0,sizeof(r));
		for(int i=0;i<m;i++){
			scanf("%d%d",&x,&y);
			if(l[x]==0) l[x]=1,l1--;
			if(r[y]==0) r[y]=1,r1--;
			printf("%lld\n",1ll*l1*r1);
		}
	}
}
