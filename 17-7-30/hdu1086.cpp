#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
using namespace std;
double fabs(double x){
	if(x<1e-8) return -x;
	else return x;
}
struct Point{
	double x,y;
	friend bool operator ==(Point a,Point b){
		if(fabs(a.x-b.x)<1e-7&&fabs(a.y-b.y)<1e-7) 
			return 1;
		else return 0;
	}
};
struct Line{
	Point p,q;
}a[110];

double xmul(Point a,Point b,Point c){
	return (a.x-c.x)*(b.y-c.y)-(a.y-c.y)*(b.x-c.x);
}

int sig(double x){
	if(x>1e-7) return 1;
	if(x<-1e-7) return -1;
	else return 0;
}

int pan(Line a,Line b){
	if(sig(xmul(a.p,a.q,b.q))*sig(xmul(a.p,a.q,b.p))>=0) return 0;
	if(sig(xmul(b.p,b.q,a.q))*sig(xmul(b.p,b.q,a.p))>=0) return 0;
	return 1;
}

int main(){
	int n;
	while(scanf("%d",&n),n){
		for(int i=0;i<n;i++){
			scanf("%lf%lf",&a[i].p.x,&a[i].p.y);
			scanf("%lf%lf",&a[i].q.x,&a[i].q.y);
		}
		int ans=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<i;j++){
				if(pan(a[i],a[j])) ans++;
				else
				if(a[i].p==a[j].p||a[i].p==a[j].q||a[i].q==a[j].p||a[i].q==a[j].q)
					ans++;
			}
		}
		cout << ans << endl;
	}
}
