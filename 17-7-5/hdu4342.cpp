#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
int n;

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		long long ans=n+(long long)sqrt(n*1.0);
		long long tmp=(long long)((sqrt(1.0+4.0*n)+1)/2.0);
		if(tmp*tmp-tmp==n) tmp--; 
		ans=n+tmp;
		tmp--;
		tmp=tmp*(tmp+1)/2+tmp*(tmp+1)*(2*tmp+1)/3+(tmp+1)*(ans-(tmp+1)*(tmp+1)+1);
		printf("%lld %lld\n",ans,tmp);
		
	}
}
