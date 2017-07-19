#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
#include <cmath>
using namespace std;
int a[100100];
int main(){
	int T,n,m,x,y;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++){
			scanf("%d%d%d",&a[i],&x,&x);
		}
		sort(a,a+n);
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d%d",&x,&y);
			long long tmp=2ll*m*x;
			tmp+=(long long)a[y-1]*a[y-1];
			double ans=sqrt(tmp*1.0);
			printf("%.3f\n",ans);
		}
	}
}
