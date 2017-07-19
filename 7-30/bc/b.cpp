#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int a[100100];
int main(){
	int n,m,T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		long long sum=n;
		for(int i=1;i<n;i++){
			scanf("%d",&a[i]);
			sum+=a[i];
		}
		a[0]=0;
		sort(a+1,a+n);
		if(m>n) m=n;
		for(int i=n-1;i>n-m;i--)
			sum-=a[i];
		printf("%lld\n",sum);
	}
}
