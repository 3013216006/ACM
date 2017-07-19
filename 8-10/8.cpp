#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;
double pi=acos(-1.0);
int main(){
	int T,l,r,vl,vr,t;
	scanf("%d",&T);
	while(T--){
		int flag=0;
		scanf("%d%d%d%d%d",&l,&r,&vl,&vr,&t);
		if(vl==vr){
			double y=vl*pi*r*2*t;
			printf("%.3f %.3f\n",0.0,y);
			continue;
		}
		if(vl<vr){
			flag=1;
			int tmp=vl;
			vl=vr;
			vr=tmp;
		}
		double v1=2*pi*r*vl,v2=2*pi*r*vr;
		double R=(v1+v2)/(v2-v1)/2.0*l;
		double theta=(v1+v2)/2.0/R*t;
		double x=R*cos(theta)-R,y=R*sin(theta);
		if(flag) x=-x;
		printf("%.3f %.3f\n",x,y);
	}
}
