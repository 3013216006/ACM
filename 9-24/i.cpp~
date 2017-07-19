#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<map>
#include<string>
#include<queue>
using namespace std;
int ta,tb,x,ta1,tb1;
int n,m,tt,tt1,temp;
struct node
{
    int d,t,c;
}a[20010],b[20010];
struct node1
{
    int t,d,id;
    bool operator<(const node1 &a)const
    {
        return t>a.t;
    }
}temp1,temp2;
int ans,ans1;
priority_queue<node1>qu;
bool cmp(node a,node b)
{
    if(a.t!=b.t)
    return a.t<b.t;
    return a.c<b.c;
}
int mark[20010];
int main()
{
    while(scanf("%d %d",&ta,&tb)!=EOF)
    {
        while(!qu.empty())qu.pop();
        scanf("%d",&x);
        scanf("%d %d",&n,&m);
        ans=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d %d %d",&a[i].t,&a[i].c,&a[i].d);
            a[i].t+=a[i].c;
        }
        for(int i=0;i<m;i++)
        {
            scanf("%d %d %d",&b[i].t,&b[i].c,&b[i].d);
            b[i].t+=b[i].c;
            ans+=b[i].d;
        }
        tb1=tb+x-1;
        sort(a,a+n,cmp);
        for(int i=0;i<n;i++)
        {
            if(a[i].t>=x&&a[i].t<=tb1)
            {
                b[m].t=a[i].t+a[i].c;
                b[m].c=a[i].c;
                b[m].d=a[i].d;
                ans+=a[i].d;
                m++;
            }
        }
        memset(mark,0,sizeof(mark));
        sort(b,b+m,cmp);
        int i=0,pos=0;
        ans1=ans;
        while(i<m)
        {
            tt=b[i].t;
            tt1=tt+ta-1;
            while(pos<m&&b[pos].t<=tt1)
            {
                temp=b[pos].t;
                if(temp>=x&&temp<=tb1)
                {
                    temp1.id=pos;
                    temp1.d=b[pos].d;
                    temp1.t=((tb1-b[pos].t)/b[pos].c+(((tb1-b[pos].t)/b[pos].c)&1))*b[pos].c;
                    qu.push(temp1);
                }
                else
                {
		    mark[pos]=1;
                    ans1-=b[pos].d;
                }
                pos++;
            }

            while(!qu.empty())
            {
                temp1=qu.top();
                if(temp1.t<=tt1)
                {
                    qu.pop();
                    if(temp1.id>=i)
                    {
                        ans1-=temp1.d;
                        mark[temp1.id]=1;
                    }
                }
                else
                    break;
            }
            ans=min(ans,ans1);
            if(mark[temp1.id])
            ans1+=b[i].d;
            i++;

        }
        printf("%d\n",ans);
    }
}
