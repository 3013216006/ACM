#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
int n,t;
double temp;
int equ,var;
int ans[22];
long long a[11][11];
long long lcm(long long a,long long b)
{
	return a/__gcd(a,b)*b;
}
void debug()
{
	for(int i=0;i<equ;i++)
	{
		for(int j=0;j<var;j++)
		{
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
}
int Gauss()
{
	int max_r,col;
	long long ta,tb;
	long long LCM;
	col=0;
	for(int k=0;k<equ&&col<var;k++,col++)
	{
		max_r=k;
		for(int i=k+1;i<equ;i++)
		{
			if(abs(a[i][col])>abs(a[max_r][col]))
				max_r=i;
		}
		if(max_r!=k)
		{
			for(int j=k;j<var+1;j++)
				swap(a[k][j],a[max_r][j]);
		}
		if(a[k][col]==0)
		{
			k--;
			continue;
		}
		for(int i=k+1;i<equ;i++)
		{
			if(a[i][col]!=0)
			{
				LCM=lcm(abs(a[i][col]),abs(a[k][col]));
				ta=LCM/abs(a[i][col]);
				tb=LCM/abs(a[k][col]);
				if(a[i][col]*a[k][col]<0)
					tb=-tb;
				for(int j=col;j<var;j++)
				{
					a[i][j]=a[i][j]*ta-a[k][j]*tb;
				}
			}
		}
	}
	//debug();
	int tot=0;
	for(int i=0;i<n;i++)
	{
		if(a[n-1][i]==0)
			tot++;
	}
	if(tot==n)
		return 1;
	else
		return 0;
}
int cnt=1;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		equ=var=n;
		memset(a,0,sizeof(a));
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				scanf("%lf",&temp);
				temp*=100.0;
				a[i][j]=(long long)temp;
			}
			a[i][i]-=100;
		}
		//debug();
		ans[cnt++]=Gauss();
	}
	for(int i=1;i<cnt;i++)
	{
		if(i%5==0||i==cnt-1)
			printf("%d\n",ans[i]);
		else
			printf("%d ",ans[i]);
	}
}
