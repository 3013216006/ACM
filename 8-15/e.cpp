#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
int a[10000000];
int main(){
	int n,m,cnt;
	while(~scanf("%d%d",&n,&m)){
		cnt=0;
		int tn=n,tm=m;
		while(tn!=tm){
			if(tn>tm) tn/=2;
				else tm/=2;
		}
		if(tn==n||tn==m){
			puts("-1");
			continue;
		}
		while(tn>1){
			a[cnt++]=tn^1;
			tn/=2;
		}
		a[cnt++]=n;
		a[cnt++]=m;
		while(n!=m){
			if(n<m){
				int tmp=n;n=m;m=tmp;
			}
			if((n^1)!=m){
				a[cnt++]=n^1;
				n/=2;
			}
			else{
				n/=2;
				m/=2;
			}
		}
		sort(a,a+cnt);
		for(int i=0;i<cnt;i++){
			if(i) printf(" ");
			printf("%d",a[i]);
		}
		puts("");
	}
}
