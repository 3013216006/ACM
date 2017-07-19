#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
long long mod;
long long b[150];
int a[150];
void init(){
	mod=1000000007ll;
	b[0]=1;
	for(int i=1;i<=100;i++)
		b[i]=b[i-1]*2%mod;
}

int main(){
	int T,cas=1;
	long long x;
	init();
	scanf("%d",&T);
	while(T--){
		scanf("%lld",&x);
		x++;
		int l=0;
		while(x){
			a[l++]=x%2;
			x/=2;
		}
		long long ans=0;
		while(l--){
			ans+=(l+1)*b[l]%mod*b[l]%mod*x%mod;
			ans%=mod;
			x=x*2+a[l];
			x%=mod;
			if(a[l]==1){
				long long sum=0;
				int sum1=1;
				int tmpl=l;
				while(tmpl--){
					sum=sum*2+a[tmpl];
					sum%=mod;
					if(a[tmpl]){
						ans+=sum1*b[tmpl]%mod*b[l]%mod;
						if(tmpl){
							ans+=tmpl*b[tmpl-1]%mod*b[l]%mod;
						}
						sum1++;
					}
					ans%=mod;
				}
				if(l){
					ans+=sum*l%mod*b[l-1]%mod;	
				}
				ans%=mod;
			}
		}
		printf("Case #%d: %lld\n",cas++,ans);
	}
}
