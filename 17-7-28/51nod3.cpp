#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <string.h>
using namespace std;

int main(){
	long long n;
	int k;
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%lld%d",&n,&k);
		if(n==0){
			puts("0");
			continue;
		}
		long long ans;
		if(k==1){
			long long tmp= (long long) sqrt(n*1.0);
			while((tmp+1)*(tmp+1)<=n) tmp++;
			if(tmp*tmp==n){
				ans=tmp*2-1;
			}
			else ans=tmp*2;
		}
		else{
			if(n==2){
				puts("1");
				continue;
			}
			if(n==1){
				puts("-1");
				continue;
			}
			if(n==3){
				puts("-1");
				continue;
			}
			if(n==4){
				puts("2");
				continue;
			}
			if(n==5){
				puts("3");
				continue;
			}
			long long tmp = (long long) sqrt(n*1.0);
			while((tmp+1)*(tmp+1)<=n) tmp++;
			if(tmp*tmp+1>=n){
				ans=tmp*2-2;
			}
			else{
				ans=tmp*2-1;
			}
		}
		printf("%lld\n",ans);
	}
}
