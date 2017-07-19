#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int a[2000];
int main(){
	int T,n,m;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		m++;
		int l=0,s=0;
		while(n){
			a[l++]=n%2;
			n/=2;
		}
		if(l>m){
			while(l>m) {
				l--;
				a[l-1]+=a[l]*2;
			}
		}
		int sum=0;
		for(int i=0;i<l;i++)
			sum+=a[i];
		printf("%d\n",sum);
	}
}
