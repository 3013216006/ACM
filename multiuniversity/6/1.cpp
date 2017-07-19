#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
long long mod=1000000007ll;
long long myget(int x,int y){
	long long ret=1,t=x;
	while(y){
		if(y&1) ret=ret*t%mod;
		t=t*t%mod;
		y>>=1;
	}
	return ret;
}

int main(){
	int T,n,m;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		long long x=myget(m,n+1);
		x=(x-1+mod)%mod;
		m--;
		long long y=myget(m,mod-2);
		long long ans=x*y%mod;
		cout << ans << endl;
	}
}
