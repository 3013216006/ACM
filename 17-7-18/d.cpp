#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
int a[10020],b[10020];
int main(){
	int T;
	int n;
	int cas=1;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			scanf("%d",&a[i]);
		for(int i=0;i<n;i++)
			scanf("%d",&b[i]);
		sort(a,a+n);
		sort(b,b+n);
		long long sum=0;
		int l=0;
		for(int i=0;i<n;i++){
			while(l<n&&b[l]<a[i]) l++;
			sum+=l;
		}
		printf("Case %d: %.2f\n",cas++,1.0*sum/n);
	}
}
