#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
double pi=acos(-1.0);

int main(){
	int T;
	int l,r,vl,vr,s;
	scanf("%d",&T);
	while(T--){
		int flag=0;
		scanf("%d%d%d%d%d",&l,&r,&vl,&vr,&s);
		if(vl==vr){
//			cout << "haha" << endl;
			printf("%.3f %.3f\n",0.0,2.0*vl*s*pi);
			continue;
		}
		if(vl<vr) flag=1,swap(vl,vr);
		double x=1.0*vr*l/(vl-vr);
		double v=(vr+vl)/2.0;
		double t=r*v*s/(x+l/2.0);
		t=t-(int)t;
		double theta=2*pi*t;
		double ansx=(x+l/2.0)-(x+l/2.0)*cos(theta);
		double ansy=(x+l/2.0)*sin(theta);
		if(flag) ansx=-ansx;
		printf("%.3f %.3f\n",ansx+1e-7,ansy+1e-7);
	}
}
