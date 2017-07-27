#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;
int a[200200];

int main(){
	int n,m;
	while(~scanf("%d%d",&n,&m)){
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		double ans=0;
		int tmp=n-m+1;
		long long anstmp=0;
		long long ans2=0;
		for(int i=1;i<=n;i++){
			int x=min(min(i,m),n-i+1);
			if(x<tmp) ans2+=1ll*a[i]*x;
			else anstmp+=1ll*a[i];
			//ans+=1.0*a[i]*x/tmp;
		}
		printf("%.8f\n",ans2*1.0/tmp+anstmp);
	}
}
