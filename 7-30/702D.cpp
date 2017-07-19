#include <iostream>
#include <stdio.h>
using namespace std;

int main(){
	long long d,k,a,b,t;
	while(~scanf("%lld%lld%lld%lld%lld",&d,&k,&a,&b,&t)){
		long long ans;
		if(a*k+t<b*k){
			long long tmp=d/k;
			ans=d*a+tmp*t;
			if(tmp)
			ans=min(ans,a*tmp*k+tmp*t-t+b*(d-tmp*k));
		}
		else{
			if(d>k) ans=k*a+(d-k)*b;
			else ans=d*a;
		}
		printf("%lld\n",ans);
	}
}
