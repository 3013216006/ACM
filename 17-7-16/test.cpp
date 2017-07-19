#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
double pi=acos(-1.0);
double x[1000],y[1000];
double dis(int i,int j){
	double xx=x[i]-x[j];
	double yy=y[i]-y[j];
	double d=sqrt(xx*xx+yy*yy);
	if(d>1+1e-4) return 2;
	if(d<1-1e-4) return -1;
	return 1;
}
int main(){
	for(int i=0;i<100;i++){
		scanf("%lf%lf",&x[i],&y[i]);
	}
	int ans=0,flag=0;
	for(int i=0;i<100;i++)
		for(int j=i+1;j<100;j++)
			if(dis(i,j)==1) ans++;
			else if(dis(i,j)>1) flag=1;
			cout << ans << " " << flag << endl;
}
