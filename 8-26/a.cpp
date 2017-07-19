#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;

double getdis(int x,int y,int xx,int yy){
	double dx=x-xx,dy=y-yy;
	return sqrt(dx*dx+dy*dy);
}
int x,y,xx,yy,v;
int main(){
	int n,m;
	while(~scanf("%d%d",&x,&y)){
		scanf("%d",&n);
		double ans=100000;
		for(int i=0;i<n;i++){
			scanf("%d%d",&xx,&yy);
			double dis=getdis(x,y,xx,yy);
			scanf("%d",&v);
			dis/=v;
			ans=min(ans,dis);
		}
		printf("%.9f\n",ans);
	}
}
