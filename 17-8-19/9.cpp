#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
long double Pi=acos(-1.0);

int main(){
	int T;
	int n;
	scanf("%d",&T);
	while(T--){
		int r1,r2;
		scanf("%d%d",&r1,&r2);
		r1*=2;
		r2*=2;
		scanf("%d",&n);
//		n=min(n,400000);
		long double y=r2*r2;
		long double x1,x2;
		x1=y/r2,x2=y/r1;
		long double d=x2-x1;
		long double h=0;
		long double ans=(r2-r1)*(r2-r1);
		long double s=x2-x1;
		long double temp=1.0;
		s=s*s;
		n--;
		while(n){
			h+=d;
			long double tp=temp*s*y*y/(temp*h*h+x1*x1)/(temp*h*h+x2*x2);
//			cout << h << endl;
//			if(tp*n<1e-8) break;
			if(n==1){
				n=0;
				ans+=tp;
			}
			else{
				n-=2;
				ans+=tp*2;
			}
		}
		printf("%.5llf\n",ans*Pi/4.0);

	}
}
