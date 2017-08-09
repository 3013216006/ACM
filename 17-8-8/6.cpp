#include <iostream>
#include <stdio.h>
using namespace std;
long long n,m;
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%lld%lld",&n,&m);
		m=min(m,n*(n-1)/2);
		long long ans=0;
		if(m>=n-1){
			ans=(n-1)*2*n-2*m;
		}
		else{
			ans=m*2+m*(m-1)*2+(m+1)*(n-m-1)*n*2+(n-m-1)*(n-m-1-1)*n;
		}
		cout << ans << endl;
	}
}
