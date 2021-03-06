#include <iostream>
#include <stdio.h>
using namespace std;

long long mypow(long long x,int k,int p){
	long long ret=1;
	while(k){
		if (k & 1) ret = (ret * x) % p;
		k >>= 1;
		x = x * x % p;
	}
	return ret;
}

long long getans(int m,int n,int p){
	if(m==0&&n==0) return 1;
	//cout << m << " " << n << endl;
	long long ret=1;
	long long div=1;
	int mm=m%p,nn=n%p;
	if(mm>nn) return 0ll;
	for(int i=1;i<=mm;i++,nn--){
		ret=(ret*nn)%p;
		div=(div*i)%p;
	}
	return ret*mypow(div,p-2,p)%p*getans(m/p,n/p,p)%p;
}

int main(){
	int n,m,p;
	while(~scanf("%d%d%d",&n,&m,&p)){
		n=n-m+1;
		cout << getans(m,n,p) << endl;
	}
}
