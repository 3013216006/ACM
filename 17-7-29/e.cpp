#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
long long sum[50020];
int main(){
	int n,m,k;
	while(~scanf("%d%d%d",&n,&m,&k)){
		long long ans=0;
		for(int i=1;i<=m;i++)
			sum[i]=m-i+1;
		sum[0]=0;
		for(int i=1;i<=m;i++)
			sum[i]+=sum[i-1];
		for(int i=1;i<=n;i++){
			int x=k/2-i;
			x=min(x,m);
			x=max(0,x);
			ans+=(n-i+1)*sum[x];
		}
		cout << ans << endl;
	}
}
