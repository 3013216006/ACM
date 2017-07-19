#include <iostream>
#include <cmath>
#include <stdio.h>
using namespace std;

int main(){
	double h1,h2,t1,t2;
	double g=10.0;
	while(~scanf("%lf%lf%lf%lf",&h1,&t1,&h2,&t2)){
		if(h2>h1){
			double tmp=h1;h1=h2;h2=tmp;
			tmp=t1;t1=t2;t2=tmp;
		}
		double dt=t2*sqrt(h1)-t1*sqrt(h2);
		double dh=sqrt(h1)-sqrt(h2);
		double ans=dt/dh;
		printf("%f\n",ans);
	}
}
