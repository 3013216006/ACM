#include <iostream>
#include <stdio.h>
using namespace std;

int main(){
	int n,l,v1,v2,k;
	while(~scanf("%d%d%d%d%d",&n,&l,&v1,&v2,&k)){
		int x=n/k;
		if(n%k) x++;
		double ans=1.0*l*(1.0*v2+v1)/((2.0*x*v2*v1-1.0*v1*v2+1.0*v2*v2));
		double t=ans+(l-1.0*ans*v2)/v1;
		printf("%.10f\n",t);
	}
}
