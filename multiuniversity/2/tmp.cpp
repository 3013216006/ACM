#include <cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
const ll Mod=1000000007;
struct Point
{
    ll x,y,c;
    Point(){}
    Point(ll _x,ll _y,ll _c=0):x(_x),y(_y),c(_c){}
    Point operator + (const Point &t)const
    {
        return Point(x+t.x,y+t.y);
    }
    Point operator - (const Point &t)const
    {
        return Point(x-t.x,y-t.y);
    }
    ll operator * (const Point &t)const
    {
        return x*t.y-y*t.x;
    }
    ll operator ^ (const Point &t)const
    {
        return x*t.x+y*t.y;
    }
    bool operator < (const Point &t)const
    {
        return x==t.x ? y<t.y : x<t.x;
    }
    bool operator == (const Point &t)const
    {
        return x==t.x && y==t.y;
    }
};
vector<Point>v,s;
int simplify()
{
    sort(v.begin(),v.end());
    int tot=0;
    for(int i=0,j=0;i<(int)v.size();i=j)
    {
        while(j<(int)v.size() && v[j]==v[i])j++;
        ll sum=0;
        for(int k=i;k<j;k++)sum+=v[k].c;
        v[tot++]=Point(v[i].x,v[i].y,sum);
    }
    v.erase(v.begin()+tot,v.end());
    return tot;
}
bool cmp(Point a,Point b)
{
    bool up[2]={0,0};
    up[0]=a.y>0 || (a.y==0 && a.x>0);
    up[1]=b.y>0 || (b.y==0 && b.x>0);
    if(up[0]^up[1])return up[0];
    return a*b ? a*b>0 : (a^a)<(b^b);
}
ll fp(ll a,ll k)
{
    ll res=1;
    while(k)
    {
        if(k&1)res=res*a%Mod;
        a=a*a%Mod;
        k>>=1;
    }
    return res;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        v.resize(n);
        for(int i=0;i<n;i++)
        {
            scanf("%lld%lld",&v[i].x,&v[i].y);
            v[i].c=1;
        }
        n=simplify();
        ll res=0;
        for(int c=0;c<n;c++)
        {
            s.clear();
            for(int i=0;i<n;i++)
            {
                if(i==c)continue;
                Point tmp=v[i]-v[c];
                s.push_back(Point(tmp.x,tmp.y,v[i].c));
            }
            sort(s.begin(),s.end(),cmp);
            ll sum=0;
            for(int i=0;i<(int)s.size();i++)
            {
                if(i>0 && s[i]*s[i-1]==0 && (s[i]^s[i-1])>0)sum+=s[i].c;
                else sum=s[i].c;
                res=(res+(fp(2,s[i].c)-1)*(fp(2,v[c].c)-1)%Mod*fp(2,sum-s[i].c))%Mod;
            }
        }
        res=res*fp(2,Mod-2)%Mod;
        for(int i=0;i<n;i++)
            res=(res+fp(2,v[i].c)-v[i].c-1)%Mod;
        printf("%lld\n",(res+Mod)%Mod);
    }
    return 0;
}
