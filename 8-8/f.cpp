#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int main(){
	long long n,m;
	while(~scanf("%lld%lld",&n,&m)){
		if(n==0&&m==0) break;
		long long ans=1,t=n+m;
		if(m<n) n=m;
		for(long long i=1;i<=n;i++,t--){
			ans*=t;
			ans/=i;
		}
		cout << ans << endl;
	}
}
