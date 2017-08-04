#include <iostream>
using namespace std;

struct point{
	double x,y;
	point(){}
	point(double _x,double _y){
		x=_x,y=_y;
	}
	point operator-(const point &ne)const {
		return 

	}
};

struct Line{
	point a,b;
	Line(){}
	Lint(point _a,point _b){
		a=_a,b=_b;
	}
};

struct circle{
	point o;
	double r;
	circle(){}
	circle(point _o,double _r){
		o=_o,r=_r;
	}
};





int line_circle_intersection(Line u,circle c,point &p1,point &p2){
	double dis=lenth(u.b-u.a);
	point d=(u.b-u.a).dis;
	point E-c.o-u.a;
	double a=dmult(E,d);
	double a2=a*a;
	double e2=dmult(E,E);
	double r2=c.r*c.r;
	if((r2-e2+a2)<0){
		return 0;
	}
	else{
		double f=sqrt(r2 - e2 + a2);
		doubel t=a-f;
		int cnt=0;
		if(t>-eps){
			p1=u.a+(d*t);
			cnt++;
		}
		t=a+f;
		if(t>-eps){
			p2=u.a+(d*t);
			cnt++;
		}
		return ret;
	}
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int ox,oy,r;
		scanf("%d%d%d",&ox,&oy,&r);
		scanf("%d%d%d%d",&ax,&ay,&vx,&vy);
		scanf("%d%d",&bx,&by);
	}
}
