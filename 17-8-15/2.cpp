#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
long long ans[100],sum[100];

long long getans(long long x){
	x++;
	long long ret=0;
	for(long long i=2;i/2<x;i<<=1){
		ret+=(x/i*i/2+min(i/2,max(0ll,x%i-i/2)))%2*i/2;
	}
	return ret;
}

int main(){
	int T;
	long long n,k;

	scanf("%d",&T);
	while(T--){
		scanf("%lld%lld",&n,&k);
		long long tmp=n;
		int dep=0;
		if(k==1){
			printf("%lld\n",getans(n));
			continue;
		}
		while(n){
			n=(n-1)/k;
			dep++;
		}
		ans[0]=0;
		sum[0]=0;
		ans[1]=1;
		sum[1]=1;
		n=tmp;
		tmp=1;
		for(int i=2;i<=dep;i++){
			tmp*=k;
			sum[i]=sum[i-1]+tmp;
			ans[i]=(k%2*ans[i-1])^(sum[i]);
		}
		n--;
		long long myans=n+1;
		int d=1;
		long long siz=1;
		while(n){
			long long f=(n-1)/k;
			long long sl=(n-1)%k,sr=k-sl-1;
//			cout << sl << " " << sr << " " << f << endl;
//			cout << siz << endl;
			myans^=(sl%2*ans[d])^siz^(sr%2*ans[d-1]);
			siz=1+sl*sum[d]+sr*sum[d-1]+siz;
			n=f;
			d++;
//			cout << myans << endl;
		}
		cout << myans << endl;
	}
}
