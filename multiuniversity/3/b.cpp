#include <iostream>
#include <stdio.h>
using namespace std;
int a[2000];
int main(){
	int n;
	while(~scanf("%d",&n)){
		long long sum1=0,sum2=0;
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
			sum1+=a[i];
		}
		if(n==1){
			double ans=a[0];
			printf("%.8f\n",ans);
			continue;
		}
		else if(n==2){
			double ans=sum1;
			ans/=n;
			printf("%.8f\n",ans);
			continue;
		}
		sum1=sum1-a[0]-a[n-1];
		sum2=a[0]+a[n-1];
		double ans=0;
		for(int i=n;i>=1;i--){
			ans=ans+(i-1.0)*(n-2)*sum2;
			ans=ans+(i-1.0)*(i-2)*sum1;
		}
		ans/=n;
		ans/=(n-1);
		ans/=(n-2);
		printf("%.8f\n",ans);
	}
}
