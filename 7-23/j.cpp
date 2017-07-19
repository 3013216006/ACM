#include <iostream>
using namespace std;
struct point{
	double x,y;
	point(){}
	point(double _x,double _y){
		x=_x,y=_y;
	}
	point operator+(const point &ne){
		return point(x+ne.x,y+ne.y);
	}
	point operator-(const point &ne){
		return point(x-ne.x,y-ne.y);
	}
	void scan(){
		scanf("%lf%lf",&x,&y);
	}
};

double xmul(point a,point b){
	return a.x*b.y-a.y*b.x;
}

double dmul(point a,point b){
	return a.x*b.x+a.y*b.y;
}

struct line{
	point a,b;
	line(){}
	line(poing _a,poinf _b){
		a=_a,b=_b;
	}
	void comp(){
		if(a.y<b.y){
			double tmp=a.x;
			a.x=b.x;
			b.x=tmp;
			tmp=a.y;
			a.y=b.y;
			b.y=tmp;
		}
	}
};

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		line a,b;
		a.a.scan();
		a.b.scan();
		b.a.scan();
		b.b.scan();
		a.comp();
		b.comp();
		if(a.a.y>b.a.y){
			if((a.a.x-b.a.x)*(b.b.x-b.a.x)<1e-8){
				puts("0.00");
				continue;
			}
		}
		else{
			if((b.a.x-a.a.x)*(a.b.x-a.a.x)<1e-8){
				puts("0.00");
				continue;
			}
			line tmp;
			tmp=b;
			b=a;
			a=tmp;
		}


	}
}
