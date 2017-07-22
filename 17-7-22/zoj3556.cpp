#include <iostream>
#include <stdio.h>
using namespace std;
long long mod=1000000007ll;

long long mypow(long long x,int k){
	long long ret=1;
	while(k){
		if(k&1) ret=ret*x%mod;
		x=x*x%mod;
		k>>=1;
	}
	return ret;
}

int main(){
	int n,m;
	while(~scanf("%d%d",&n,&m)){
		long long tmp=2;
		long long t1=mypow(tmp,m);
		t1-=1;
		long long ans=mypow(t1,n);
		cout << ans << endl;
	}
}
