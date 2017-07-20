#include <iostream>
#include <math.h>
#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
struct Mat{
	long long m[2][2];
};
long long mod=1000000007ll;
Mat mul(Mat a,Mat b){
	Mat ret;
	memset(ret.m,0,sizeof(ret.m));
	for(int i=0;i<2;i++)
		for(int j=0;j<2;j++)
			for(int k=0;k<2;k++){
				ret.m[i][j]+=a.m[i][k]*b.m[k][j]%mod;
				ret.m[i][j]%=mod;
			}
	return ret;
}

Mat getpow(Mat a,int k){
	Mat ret;
	for(int i=0;i<2;i++)
		for(int j=0;j<2;j++)
			ret.m[i][j]=i==j;
	while(k){
		if(k&1) ret=mul(ret,a);
		a=mul(a,a);
		k>>=1;
	}
	return ret;
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		Mat a;
		a.m[0][0]=7;
		a.m[0][1]=12;
		a.m[1][0]=4;
		a.m[1][1]=7;
		if(n==0){
			puts("1");
			continue;
		}
		a=getpow(a,n-1);
		long long ans=7*(a.m[0][0])+4*(a.m[0][1]);
		ans*=2;
		ans%=mod;
		ans=(ans-1+mod)%mod;
		printf("%lld\n",ans);
	}
}
