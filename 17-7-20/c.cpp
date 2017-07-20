#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
struct point{
	double x,y;
	point(){}
	point(double _x,double _y){
		x=_x,y=_y;
	}
}a,b,s;
double xmul(point a,point b,point c){
	return (b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y);
}
double dis(point a,point b){
	double x=a.x-b.x;
	double y=a.y-b.y;
	return sqrt(x*x+y*y);
}

point getcenter(point a,point b,double r,point c){
	double d=dis(a,b);
	point tmp=point(a.x-b.x,a.y-b.y);
	if(d==0){
		tmp.x=a.x-c.x;
		tmp.y=a.y-c.y;
		double lll=sqrt(tmp.x*tmp.x+tmp.y*tmp.y);
		if(lll==0){
			tmp.x=1;
			tmp.y=0;
		}
		else{
		tmp.x/=lll;
		tmp.y/=lll;
		}
	}
	else tmp.x/=d,tmp.y/=d;
	point C= point(tmp.x*(d+r)/2+b.x,tmp.y*(d+r)/2+b.y);
	return C;
}

double getans(point a,double r,point b,point d){
	double l=(dis(a,b)+r)/2.0;
	point c = getcenter(a,b,r,d);
	if(dis(c,d)<l-1e-8) return -1;
	else return l;
}
point tmp;
int pan(point a,double d1,point dx,double r1,point o,double r){
	double d=sqrt(r1*r1-d1*d1);
	point o1=point(a.x+dx.x*d,a.y+dx.y*d);
	if(dis(o1,o)+r1<r+1e-8){
		tmp=o1;
		return 1;
	}
	else return 0;
}

double getans2(point o,point a,point b,double r1){
	double l=0,r=r1;
	point d=point(a.y-b.y,-a.x+b.x);
	point d1=point(d.x+(a.x+b.x)/2,d.y+(a.y+b.y)/2);
	if(xmul(d1,a,b)*xmul(o,a,b)<0){
		d.x=-d.x;
		d.y=-d.y;
	}
	point o1=point((a.x+b.x)/2,(a.y+b.y)/2);
	double tmp=sqrt(d.x*d.x+d.y*d.y);
	if(tmp<1e-8){
		return -1;
	}
	d.x/=tmp;
	d.y/=tmp;
	double tmpdis=dis(a,b)/2;
	int t=0;
	l=dis(a,b)/2;
	while(r-l>1e-6){
		double mid=(l+r)/2;
		int t=pan(o1,tmpdis,d,mid,o,r1);
		if(t) l=mid;
		else r=mid;
	}
	pan(o1,tmpdis,d,l,o,r1);
	return l;
}
void print(point a){
	printf("%.8f %.8f\n",a.x,a.y);
}

int main(){
	int T;
	double r;
	point a,b,s;
	scanf("%d",&T);
	while(T--){
		scanf("%lf%lf",&s.x,&s.y);
		scanf("%lf",&r);
		scanf("%lf%lf",&a.x,&a.y);
		scanf("%lf%lf",&b.x,&b.y);
		double ans1=getans(s,r,a,b);
		double ans2=getans(s,r,b,a);
		double ans3=getans2(s,a,b,r);
//		cout << ans1 << " " << ans2 << " " << ans3 << endl;
		if(ans1+1e-8>ans2&&ans1+1e-8>ans3){
			printf("%.8f\n",ans1);
			print(getcenter(s,a,r,b));
		}
		else if(ans2+1e-8>ans3){
		
			printf("%.8f\n",ans2);
			print(getcenter(s,b,r,a));
		}
		else{
			printf("%.8f\n",ans3);
			print(tmp);
		}
	}
}
