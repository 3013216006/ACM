#include<stdio.h>
#include<string.h>
struct node
{
    long long x,y;
}a[100005],b[100005];
long long mul(node p1,node p2,node p3)
{
    return (p2.x-p1.x)*(p3.y-p1.y)-(p3.x-p1.x)*(p2.y-p1.y);
}
int main()
{
    int n,m,i,low,high,mid,flag;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0;i<n;i++)
            scanf("%lld%lld",&a[i].x,&a[i].y);
        scanf("%d",&m);
        for(i=0;i<m;i++)
            scanf("%lld%lld",&b[i].x,&b[i].y);
        flag=0;
        for(i=0;i<m;i++)
        {
            if(mul(a[0],a[1],b[i])>=0||mul(a[0],a[n-1],b[i])<=0)
            {
                flag=1;
                goto loop;
            }
            low=2;  high=n-1;
            while(low<high)
            {
                mid=(low+high)>>1;
                if(mul(a[0],a[mid],b[i])>0)
                    high=mid;
                else low=mid+1;
            }
            if(mul(a[low],a[low-1],b[i])<=0)
            {
                flag=1;
                goto loop;
            }
        }
loop:    if(flag)
            printf("NO\n");
         else printf("YES\n");
    }
    return 0;
}
