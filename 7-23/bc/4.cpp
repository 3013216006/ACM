#include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>
using namespace std;
int prim[100100],a[100100];
int main(){
	int T,n,d;
	memset(a,0,sizeof(a));
	int l=0;
	prim[0]=0;
	l++;
	for(int i=2;i<100000;i++)
		if(a[i]==0){
			prim[l++]=i;
			for(int j=i+i;j<100000;j+=i)
				a[j]=1;
		}
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&d);
		n--;
		n=n/d;
		n=min(n,d);
		int ans=0;
		while(prim[ans+1]<=n){
			ans++;
			if(d%prim[ans]==0) break;
		}
		printf("%d\n",ans);
	}
}
