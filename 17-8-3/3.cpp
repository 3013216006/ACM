#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <time.h>
#include <stdlib.h>
using namespace std;
int prime[1000000];
long long a[1000010],pl;
long long mod=998244353ll;
void init(){
	memset(a,0,sizeof(a));
	for(int i=2;i<=1000000;i++){
		if(a[i]) continue;
		prime[pl++]=i;
		for(int j=i+i;j<=1000000;j+=i){
			a[j]=1;
		}
	}
}
long long v[1000010];
long long myk[100];
int main(){	
	pl=0;
	init();
	int T;
	long long l,r,k;
	scanf("%d",&T);
	while(T--){
		scanf("%lld%lld%lld",&l,&r,&k);
//	cout << l << " " << r << " " << k << endl;
		myk[0]=1;
		for(int i=1;i<100;i++) 
			myk[i]=(myk[i-1]+k)%mod;
		for(int i=0;i<=r-l;i++){
			a[i]=l+i;
			v[i]=1;
		}
		int k1;
		long long tmp;
		int tmp1=r-l;
//		int count=0;
		for(int i=0;i<pl&&1ll*prime[i]*prime[i]<=r;i++){
			int cnt=prime[i];
			k1=0;
			for(int j=1ll*((l-1)/prime[i]+1)*prime[i]-l;j<=tmp1;j+=prime[i]){
				if(k1>1||cnt<prime[i]-1){
					if(k1>1) cnt=0,k1=1;
					cnt++;
					a[j]/=prime[i];
					v[j]=v[j]*myk[k1];
					if(v[j]>=mod) v[j]%=mod;
					continue;
				}
//				if(tmp>=tmpdiv)
				k1=0;
				//a[j]/=prime[i];
				while(a[j]%prime[i]==0) a[j]/=prime[i],k1++;
//				if(i==0) count++;
				v[j]=v[j]*myk[k1];
				if(v[j]>=mod) v[j]%=mod;
			}
		}
//		cout << count << endl;
		long long ans=0;
		for(int i=0;i<=tmp1;i++){
			if(a[i]==1) ans+=v[i];
			else ans+=v[i]*myk[1]%mod;
//			cout << ans << endl;
		}
		ans%=mod;
		cout << ans << endl;
	}
}
