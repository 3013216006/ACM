#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;
double pi=acos(-1.0);
int main(){
	int T;
	double r=10000;
	double theta=acos(-r*r/(2*r*r*sqrt(2.0)));
	theta=pi-theta;
	double theta1=acos((5.0*r*r/(4*r*r*sqrt(2.0))));
	scanf("%d",&T);
	while(T--){
		scanf("%lf",&r);
		r/=2.0;
	double sobc=r*r*sqrt(7.0)/2.0;
	double ans=theta*r*r-theta1*2*r*2*r+sobc;
	printf("%.2f\n",ans*2.0);
	}
	
}
