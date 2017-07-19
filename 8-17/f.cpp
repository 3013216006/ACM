#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

struct Point
{
    int x,y,id;
    Point(int _x = 0, int _y = 0,int _id=0)
    {
        x = _x;
        y = _y;
        id=_id;
    }
    Point operator -(const Point &b)const
    {
        return Point(x - b.x, y - b.y,0);
    }
    int operator ^(const Point &b)const
    {
        return x*b.y - y*b.x;
    }
    int operator *(const Point &b)const
    {
        return x*b.x + y*b.y;
    }
    void input()
    {
        scanf("%d%d",&x,&y);
    }
};
int abs(int x){
	if(x<0) return -x;
		else return x;
}
Point mul(Point a,Point b){
	a=a-b;
	return Point(abs(a.x),abs(a.y));
}
double dist2(Point a,Point b)
{
    a=mul(a,b);
    if(a.x<a.y) return a.x*sqrt(2.0)+a.y-a.x;
    	else return a.y*sqrt(2.0)+a.x-a.y;
}
const int MAXN = 200010;
Point list[MAXN];
int Stack[MAXN],top;
bool _cmp(Point p1,Point p2)
{
    int tmp = (p1-list[0])^(p2-list[0]);
    if(tmp > 0)return true;
    else if(tmp == 0 && dist2(p1,list[0]) <= dist2(p2,list[0]))
        return true;
    else return false;
}
void Graham(int n)
{
    Point p0;
    int k = 0;
    p0 = list[0];
    for(int i = 1;i < n;i++)
        if(p0.y > list[i].y || (p0.y == list[i].y && p0.x > list[i].x))
        {
            p0 = list[i];
            k = i;
        }
    swap(list[0],list[k]);
    sort(list+1,list+n,_cmp);
    if(n == 1)
    {
        top = 1;
        Stack[0] = 0;
        return;
    }
    if(n == 2)
    {
        top = 2;
        Stack[0] = 0;
        Stack[1] = 1;
        return;
    }
    Stack[0] = 0;
    Stack[1] = 1;
    top = 2;
    for(int i = 2;i < n;i++)
    {
        while(top > 1 && ((list[Stack[top-1]]-list[Stack[top-2]])^(list[i]-list[Stack[top-2]])) <= 0 )
            top--;
        Stack[top++] = i;
    }
}
int ansx,ansy;
//旋转卡壳，求两点间距离平方的最大值
int rotating_calipers(Point p[],int n)
{
    double ans = 0;
    Point v;
    int cur = 1;
    for(int i = 0;i < n;i++)
    {
        v = p[i]-p[(i+1)%n];
        while((v^(p[(cur+1)%n]-p[cur])) < 0)
            cur = (cur+1)%n;
        //printf("%d %d\n",i,cur);
        double tmp=ans;
        if(ans<dist2(p[i],p[cur])){
        	ans=dist2(p[i],p[cur]);
        	ansx=p[i].id,ansy=p[cur].id;
        }
        if(ans<dist2(p[(i+1)%n],p[(cur+1)%n])){
        	ans=dist2(p[(i+1)%n],p[(cur+1)%n]);
        	ansx=p[(i+1)%n].id,ansy=p[(cur+1)%n].id;
        }
        //ans = max(ans,max(dist2(p[i],p[cur]),dist2(p[(i+1)%n],p[(cur+1)%n])));
    	
    }
    return ans;
}
Point p[MAXN];
int main()
{
    int n;
    while(scanf("%d",&n) == 1)
    {
        for(int i = 0;i < n;i++){
            list[i].input();
		list[i].id=i;
	}
        Graham(n);
        for(int i = 0;i < top;i++){
            p[i] = list[Stack[i]];
	
	}
            rotating_calipers(p,top);
            cout << ansx+1 << " " << ansy+1 <<endl;
    }
    return 0;
}
