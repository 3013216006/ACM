#include <iostream>
#include <cmath>
#include <stdio.h>
#include <algorithm>
#define sign(x) ((x)>1e-8?1:((x)<-1e-8?(-1):(0)))
using namespace std;
struct point3{
	double x,y,z;
	point3(){}
	point3(double _x,double _y,double _z){
		x=_x,y=_y,z=_z;
	}
	point3 operator-(const point3 &ne){
		return point3(x-ne.x,y-ne.y,z-ne.z);
	}
	point3 operator+(const point3 &ne){
		return point3(x+ne.x,y+ne.y,z+ne.z);
	}
	point3 operator*(const double tim){
		return point3(x*tim,y*tim,z*tim);
	}
	point3 operator/(const double tim){
		return point3(x/tim,y/tim,z/tim);
	}
};
struct line3{
	point3 a,b;
	line3(){}
	line3(point3 _a,point3 _b){
		a=_a,b=_b;
	}
};
struct plane3{
	point3 a,b,c;
	plane3(){}
	plane3(point3 _a,point3 _b,point3 _c){
		a=_a,b=_b,c=_c;
	}
};

point3 xmult(point3 a,point3 b){
	return point3(a.y*b.z-a.z*b.y,a.z*b.x-a.x*b.z,a.x*b.y-a.y*b.x);
}

double dmult(point3 a,point3 b){
	return a.x*b.x+a.y*b.y+a.z*b.z;
}

double Len(point3 a){
	return sqrt(a.x*a.x+a.y*a.y+a.z*a.z);
}

point3 normalize(point3 a){
	double len=Len(a);
	return a/len;
}

point3 pvec(plane3 s){
	return xmult(s.b-s.a,s.c-s.a);
}

bool point_on_plane(point3 a,plane3 s){
	return sign(dmult(a-s.a,pvec(s)))==0;
}
point3 line_interseciton(line3 u,line3 v){
	point3 ret=u.a,v1=xmult(u.a-v.a,v.b-v.a),v2=xmult(u.b-u.a,v.b-v.a);
	double t=Len(v1)/Len(v2)*(dmult(v1,v2)>0?-1:1);
	return ret+((u.b-u.a)*t);
}

void print(point3 x){
	printf("%.3f %.3f %.3f\n",x.x,x.y,x.z);
}

int main(){
	point3 a[4];
	while(~scanf("%lf%lf%lf",&a[0].x,&a[0].y,&a[0].z)){
		for(int i=1;i<4;i++)
			scanf("%lf%lf%lf",&a[i].x,&a[i].y,&a[i].z);
		plane3 s1=plane3(a[0],a[1],a[2]);
		if(point_on_plane(a[3],s1)){
			puts("O O O O");
			continue;
		}
		line3 l1=line3(a[0],(a[1]+a[2])*0.5);
		line3 l2=line3(a[1],(a[0]+a[2])*0.5);
	//	l1=line3(point3(2,1,0),point3(3,0,0));
	//	l2=line3(point3(-1,0,0),point3(0,1,0));
		point3 ans=line_interseciton(l1,l2);
		print(ans);
		l1=line3(a[1],(a[2]+a[3])*0.5);
		l2=line3(a[2],(a[1]+a[3])*0.5);
		plane3 s2=plane3(a[1],a[2],a[3]);
		point3 ans2=line_interseciton(l1,l2);
		print(ans2);
		line3 l3=line3(ans,a[3]);
		line3 l4=line3(ans2,a[0]);
		point3 ans3=line_interseciton(l3,l4);
		print(ans3);
	}
}
