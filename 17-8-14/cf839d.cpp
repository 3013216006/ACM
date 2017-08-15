#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int a[1000100],b[1001000];
long long mod=1000000007ll;

long long getpow(long long x,long long k){
	long long ret=1;
	while(k){
		if(k&1) ret=ret*x%mod;
		x=x*x%mod;
		k>>=1;
	}
	return ret;
}

int main(){
	int n;
	int x;
	while(~scanf("%d",&n)){
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		int mx=0;
		for(int i=0;i<n;i++){
			scanf("%d",&x);
			a[x]++;
			mx=max(mx,x);
		}
		long long ans=0;
		for(int i=2;i<=mx;i++){
			int sum=a[i];
			for(int j=i+i;j<=mx;j+=i){
				sum+=a[j];
				b[j]+=i;
				b[j]-=b[i];
			}
			if(sum){
				b[i]=i-b[i];
				ans=(ans+1ll*getpow(2,sum-1)*b[i]%mod*sum%mod)%mod;
			}
		}
		cout << ans << endl;
	}
}
