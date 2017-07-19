#include <iostream>
#include <stdio.h>
using namespace std;
int a[20],b[20];
long long mod=1000000007ll;
int n;
long long getans(int xx,int k){
	long long ret=1,x=xx;
	while(k){
		if(k&1){
			ret*=x;
			ret%=mod;
		}
		x=x*x%mod;
		k>>=1;
	}
	return ret;
}
int main(){
	while(~scanf("%d",&n)){
		for(int i=0;i<n;i++){
			scanf("%d%d",&a[i],&b[i]);
		}
		int l=1<<n;
		long long ans=0;
		for(int i=1;i<l;i++){
			int x=0,y=0;
			for(int j=0;j<n;j++){
				if(i&(1<<j)){
					x=max(x,a[j]);
					y=max(y,b[j]);
				}
			}
			ans+=getans(2,x)*getans(3,y)%mod;
			ans%=mod;
		}
		cout << ans << endl;
	}
}
