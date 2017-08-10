#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <iomanip>
using namespace std;

const double eps = 1e-6;
double pi, x, y, dis;
int x1, Y1, x2, y2, R, tt;
double cos1, cos2, deg1, deg2, degl, degr, mid1, mid2, dis1, dis2, t, epss;
int main()
{
    pi = acos(-1);
    scanf("%d", &tt);
    while(tt--)
    {
        scanf("%d", &R);
        scanf("%d%d", &x1, &Y1);
        scanf("%d%d", &x2, &y2);
        if (x1 == 0 && Y1 == 0) {printf("%d\n", R); continue;}
        cos1 = (1.0*x1)/sqrt((1.0*x1*x1+1.0*Y1*Y1));
        cos2 = (1.0*x2)/sqrt((1.0*x2*x2+1.0*y2*y2));
        deg1 = acos(cos1);
        if (Y1 < 0) deg1 = 2.0*pi-deg1;
        deg2 = acos(cos2);
        if (y2 < 0) deg2 = 2.0*pi-deg2;
        if (deg1 > deg2) {t = deg1; deg1 = deg2; deg2 = t;}
//        cout<<deg1/pi*180<<' '<<deg2/pi*180<<endl;
        //if (deg2 - deg1 < pi)
       // {
       //     degl = deg1; degr = (deg2+deg1)/2;
       // } else{
        //    degl = deg2; degr = (deg2+deg1)/2-pi;
        //    if (degr < 0) degr += 2.0*pi;
       // }
		double l=sqrt(x1*x1+Y1*Y1);
     //   x = R*cos(deg1); y = R*sin(deg1);
      //  dis1 = sqrt((x-x1)*(x-x1)+(y-Y1)*(y-Y1)) + sqrt((x-x2)*(x-x2)+(y-y2)*(y-y2));
      //  x = R*cos(degr); y = R*sin(degr);
      //  dis2 = sqrt((x-x1)*(x-x1)+(y-Y1)*(y-Y1)) + sqrt((x-x2)*(x-x2)+(y-y2)*(y-y2));
      //  if (dis1 > dis2) dis1 = dis2;
     //   epss = eps * dis1;
     //   if (degl > degr) {t = degl; degl = degr; degr = t;}
        double xx,yy;
		double degl=0,degr=(deg2-deg1)/2;
		x1=l*cos(deg2-deg1),Y1=l*sin(deg2-deg1);
	
        while(degl + eps<degr)
            {
                //cout<<degl<<' '<<degr<<endl;
                mid1 = (degr-degl)/3 + degl;
                mid2 = mid1+(degr-degl)/3;
                x = R*cos(mid1); y = R*sin(mid1);
                xx=x-x1,yy=y-Y1;
                dis1 = sqrt(xx*xx+yy*yy)+sqrt((x-l)*(x-l)+y*y);
                x = R*cos(mid2); y = R*sin(mid2);
                xx=x-x1,yy=y-Y1;
                dis2 = sqrt(xx*xx+yy*yy)+sqrt((x-l)*(x-l)+y*y);
                //dis2 = sqrt((x-x1)*(x-x1)+(y-Y1)*(y-Y1)) + sqrt((x-x2)*(x-x2)+(y-y2)*(y-y2));
        //        if (fabs(dis1-dis2) < epss) {degl = mid1; deg2 = mid2; break;}
                //cout<<dis1<<' '<<dis2<<endl;
//				cout << dis1 << " " << dis2 << endl;
		if(fabs(dis1-dis2)/dis1<3*1e-8){l=mid1,r=mid2;break;}  
                if (dis1 < dis2) degr = mid2; else degl = mid1;
            }
        mid1 = (degr+degl)/2;
  //      cout << mid1/pi*180 << endl;
        x = R*cos(mid1); y = R*sin(mid1);
        xx=x-x1,yy=y-Y1;
        dis1 = sqrt(xx*xx+yy*yy)+sqrt((x-l)*(x-l)+y*y);
//        dis1 = sqrt((x-x1)*(x-x1)+(y-Y1)*(y-Y1)) + sqrt((x-x2)*(x-x2)+(y-y2)*(y-y2));
        printf("%.7f\n", dis1);
    }
}
