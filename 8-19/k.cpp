#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cmath>
using namespace std;
struct Node{
	int x,y;
}a[100];
double d[100];
int mark[100];

double dis(Node a,Node b){
	double x=a.x-b.x;
	double y=a.y-b.y;
	return sqrt(x*x+y*y);
}

int main(){
	int n,x,y;
	while(~scanf("%d",&n)){
		if(n==0) break;
		scanf("%d%d",&x,&y);
		for(int i=1;i<=n;i++){
			scanf("%d%d",&a[i].x,&a[i].y);
		}
		memset(mark,0,sizeof(mark));
		mark[x]=1;
		mark[y]=1;
		double ans=dis(a[x],a[y]);
		for(int i=1;i<=n;i++){
			if(mark[i]) continue;
			d[i]=min(dis(a[i],a[x]),dis(a[i],a[y]));
		}
		for(int i=2;i<n;i++){
			double tmp=300;
			int x=-1;
			for(int j=1;j<=n;j++){
				if(mark[j]) continue;
				if(d[j]<tmp){
					tmp=d[j];
					x=j;
				}
			}
			mark[x]=1;
			ans+=d[x];
			for(int j=1;j<=n;j++)
			if(mark[j]==0){
				d[j]=min(d[j],dis(a[j],a[x]));
			}
		}
		printf("%.2f\n",ans);
	}
}
