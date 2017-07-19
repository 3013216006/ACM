#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <math.h>
using namespace std;

int main(){
	int n,m;
	while(~scanf("%d%d",&n,&m)){
		double ans=360;
		int tmp=-1;
		for(int i=3;i<=n;i++){
			double tans=180.0/n*(i-2);
	//		cout << tans << endl;
			if(fabs(tans-m)<ans-1e-5) {
				ans=fabs(tans-m);
				tmp=i;
			}
		}
		printf("2 1 %d\n",tmp);
	}
}
