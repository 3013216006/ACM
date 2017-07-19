#include<cstdio>
#include<algorithm>
#include<cstring>
#include<map>
#include<iostream>
#include<cmath>
using namespace std;
int n,t;
int a,b,c;
long long d[4];
struct point
{
	int x,y,z;
}p[210];
point xmult(point a,point b)
{
	point c;
	c.x=a.y*b.z-a.z*b.y;
	c.y=b.x*a.z-a.x*b.z;
	c.z=a.x*b.y-b.x*a.y;
	return c;
}
point smult(point a,point b)
{
	point c;
	c.x=a.x-b.x;
	c.y=a.y-b.y;
	c.z=a.z-b.z;
	return c;
}
double dot(point a,point b)
{
	return a.x*b.x+a.y*b.y+a.z*b.z;
}
point prec(point a,point b,point c)
{
	return xmult(smult(a,b),smult(b,c));
}
bool check1(point a,point b,point c,point d)
{
	if(dot(prec(a,b,c),smult(d,a))==0.0000)
		return true;
	return false;
}
int temp,temp1;
int dis[210][210];
double dis1[210][210];
int cnt=1;
int check(int i,int j,int k)
{
	double sum=dis1[i][j]+dis1[j][k]+dis1[i][k];
	int sum1=dis[i][j]+dis[j][k]+dis[i][k];
	if(sum-dis1[i][j]>dis1[i][j]&&
		sum-dis1[j][k]>dis1[j][k]&&
		sum-dis1[i][k]>dis1[i][k]
		)
	{
		if(dis[i][j]==dis[j][k]&&
			dis[i][k]==dis[j][k])
			return temp=dis[i][k];
		else if(dis[i][j]==dis[j][k]||
			dis[i][k]==dis[j][k]||
			dis[i][k]==dis[i][j])
			return temp=((sum1-(dis[i][j]^dis[j][k]^dis[i][k]))/2);
		else
			return 0;
	}
	else
		return 0;
}

int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%d %d %d",&p[i].x,&p[i].y,&p[i].z);
		}
		int ans=0;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				dis[i][j]=abs(p[i].x-p[j].x)*abs(p[i].x-p[j].x)
				+abs(p[i].y-p[j].y)*abs(p[i].y-p[j].y)
				+abs(p[i].z-p[j].z)*abs(p[i].z-p[j].z);
				dis1[i][j]=sqrt(dis[i][j]);
			}
		}
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				for(int k=j+1;k<n;k++)
				{
					if(check(i,j,k))
					{
						temp1=temp;
						for(int l=k+1;l<n;l++)
						{
							if(check(i,j,l)==temp1&&check(i,k,l)==temp1&&check(j,k,l)==temp1)
							{
								//cout<<i<<" "<<j<<" "<<k<<" "<<l<<endl;
								//cout<<dis[i][j]<<" "<<dis[i][k]<<" "<<dis[i][l]<<" "<<dis[j][k]<<" "<<dis[j][l]<<" "<<dis[k][l]<<endl;
								//cout<<dis1[i][j]<<" "<<dis1[i][k]<<" "<<dis1[i][l]<<" "<<dis1[j][k]<<" "<<dis1[j][l]<<" "<<dis1[k][l]<<endl;
								if(check1(p[i],p[j],p[k],p[l]))
									ans++;
							}
						}
					}
				}
			}
		}
		printf("Case #%d: %d\n",cnt++,ans);
	}
}

