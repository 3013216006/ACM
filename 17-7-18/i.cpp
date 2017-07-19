#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
struct Node{
	int x,y;
}a[20];

long long dist(int i,int j){
	long long x=a[i].x-a[j].x;
	long long y=a[i].y-a[j].y;
	return x*x+y*y;
}

int getmul(Node a,Node b,Node c){
	long long tmp=1ll*(b.x-a.x)*(c.y-a.y)-1ll*(b.y-a.y)*(c.x-a.x);
	if(tmp>0) return 1;
	if(tmp<0) return -1;
	return 0;
}
long long dis[20][20];
int xmul[11][11][11];
int vis[20];
int main(){
	int T,cas=1;
	int n;
	scanf("%d",&T);
	while(T--){
		memset(vis,0,sizeof(vis));
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d%d",&a[i].x,&a[i].y);
		}
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++){
				dis[i][j]=dist(i,j);
				dis[j][i]=dist(i,j);
			}
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				for(int k=0;k<n;k++)
					xmul[i][j][k]=getmul(a[k],a[i],a[j]);
		int ans=0;
		for(int i=0;i<n;i++){
			vis[i]=1;
			for(int j=i+1;j<n;j++){
				if(vis[j]) continue;
				vis[j]=1;
				for(int i1=0;i1<n;i1++){
					if(vis[i1]) continue;
					vis[i1]=1;
					for(int j1=i1+1;j1<n;j1++){
						if(vis[j1]) continue;
						if(dis[i][j]!=dis[i1][j1]) continue;
						vis[j1]=1;
						for(int k=0;k<n;k++){
							if(xmul[i][j][k]==0) continue; 
							if(vis[k]) continue;
							for(int k1=0;k1<n;k1++){
								if(xmul[i1][j1][k1]==0) continue;
								if(vis[k1]||k==k1) continue;
								if(dis[i][k]==dis[i1][k1]&&dis[j][k]==dis[j1][k1]){
									if(xmul[i][j][k]==xmul[i1][j1][k1]){
										ans++;
									}
								}
								if(dis[i][k]==dis[j1][k1]&&dis[j][k]==dis[i1][k1]){
									if(xmul[i][j][k]==xmul[j1][i1][k1]) ans++;
								}
							}
						}
						vis[j1]=0;
					}
					vis[i1]=0;
				}
				vis[j]=0;
			}
			vis[i]=0;
		}
		printf("Case %d: %d\n",cas++,ans/3);
	}
}
