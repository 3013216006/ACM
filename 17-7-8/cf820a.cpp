#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
using namespace std;

int main(){
	int c,v0,v1,a,l;
	while(~scanf("%d%d%d%d%d",&c,&v0,&v1,&a,&l)){
		int b=2*(v0-l)-a,C=2*(l-c);
		if(a==0){

			int t=(int) ((c-l)*1.0/(v0-l)+1-1e-6);
			t=max(1,t);
			cout << t << endl;
			continue;
		}
		int t1=(v1-v0)/a+1;
		int tmp=t1*(t1-1)*a/2+(v0-l)*t1+l;
		if(tmp>c){
			double d=sqrt(1.0*b*b-4.0*a*C);
			int ans=(int) ((d-b)/(2.0*a)+1-1e-6);
			ans=max(ans,1);
			cout << ans << endl;
		}
		else{
			c-=tmp;
			int t2=c/(v1-l);
			if(c%(v1-l)) t2++;
			cout << t1+t2 << endl;
		}
	}
}
