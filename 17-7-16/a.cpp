#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string.h>
using namespace std;
double pi=acos(-1.0);
double x[100],y[100];
double dis(double xx,double yy,double x,double y){
	xx-=x;
	yy-=y;
	return sqrt(xx*xx+yy*yy);
}
int main(){
	int T;
	x[0]=0.000000,y[0]=0.525731;
	x[1]=-0.500000,y[1]=0.162460;
	x[2]=-0.309017,y[2]=-0.425325;
	x[3]=0.309017,y[3]=-0.425325;
	x[4]=0.500000,y[4]=0.162460;
	scanf("%d",&T);
	for(int i=0;i<5;i++)
		for(int j=i+1;j<5;j++)
		;//	cout << i << " " << j << " " << dis(x[i],y[i],x[j],y[j]) << endl;
	while(T--){
		int n;
		scanf("%d",&n);
		if(n<=3) puts("No");
		else{
			puts("Yes");
			printf("%.6f %.6f\n",0.0,0.0);
			printf("%.6f %.6f\n",cos(30.0/180*pi),-sin(30.0/180*pi));
			printf("%.6f %.6f\n",1.0,0.0);
			for(int i=4;i<n;i++){
				double tmp=30.0/180/n*i;
	//			cout << tmp << endl;
				printf("%.6f %.6f\n",cos(tmp*pi),sin(tmp*pi));
			}
			printf("%.6f %.6f\n",cos(30.0/180*pi),-sin(30.0/180*pi));
		}
	}
}
