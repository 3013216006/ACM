#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
double dp[1<<20],p[22];
int main(){
	int n;
	while(~scanf("%d",&n)){
		for(int i=0;i<n;i++)
			scanf("%lf",&p[i]);
		int l=1<<n;
		for(int i=1;i<l;i++){
			dp[i]=1;
			double sum=0;
			for(int j=0;j<n;j++){
				if(i&(1<<j)){
					sum+=p[j];
				}
			}
			dp[i]/=sum;	
			for(int j=0;j<n;j++){
				if(i&(1<<j)){
					dp[i]+=dp[i-(1<<j)]*(p[j]/sum);
				}
			}
		}
		printf("%.3f\n",dp[(1<<n)-1]);
	}
}
