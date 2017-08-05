#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
double pi=acos(-1.0);
double eps=1e-8;
int main(){
	int r,l,w;
	double a,b;
	scanf("%d%d%d",&r,&l,&w);
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%lf%lf",&a,&b);
		double ans=r*2;
		ans=min(ans,w*1.0);
		ans=min(ans,l*1.0);
		if(a<pi/2+eps){
			ans=min(ans,l*sin(a));
		}
		if(b>pi/2-eps){
			ans=min(ans,w-l*sin(b));
		}
		else{
			if(w*sin(b)>l+eps)
				ans=min(ans,sqrt((l*cos(b))*(l*cos(b))+(w-l*sin(b))*(w-l*sin(b))));
			else
			ans=min(ans,w*cos(b));
			if(a<pi/2+eps){
				if(l*cos(b)/tan(a)+l*sin(b)>w-eps)
					ans=min(ans,w*cos(a)-l*sin(b-a));
				else
					ans=min(ans,sqrt((l*cos(b))*(l*cos(b))+(w-l*sin(b))*(w-l*sin(b))));
			}
		}
		ans=ans/2;
		printf("%.8f\n",ans);
	}
}
