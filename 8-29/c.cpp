#include <iostream>
#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;
long long v[110][110],b[110][110][110],d[110][2];
int c[110],a[110];
struct Node{
	long long x;
	int y;
	Node(){}
	Node(long long _x,int _y){
		x=_x,y=_y;
	}
	friend bool operator<(const Node a,const Node b){
		return a.x<b.x;
	}
};
priority_queue<Node> Q;
int main(){
	int n,m,l;
	while(~scanf("%d%d%d",&n,&m,&l)){
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++){
				scanf("%lld",&v[i][j]);
			}
		long long ma=1ll<<60;
		for(int i=0;i<=n;i++)
			for(int j=0;j<=m;j++)
				for(int k=0;k<=l;k++)
					b[i][j][k]=ma;
		c[0]=0;
		d[0][0]=0;
		for(int i=1;i<=l;i++){
			c[i]=0;
			d[i][0]=ma;
		}
		b[0][0][0]=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++)
				for(int k=1;k<=l;k++){
					if(a[i]==0){
						b[i][j][k]=min(b[i-1][j][k]+v[i][j],b[i][j][k]);
						if(c[k-1]==j) b[i][j][k]=min(b[i][j][k],d[k-1][1]+v[i][j]);
							else b[i][j][k]=min(b[i][j][k],d[k-1][0]+v[i][j]);
					}
					else{
						if(a[i]==j){
							b[i][j][k]=b[i-1][j][k];
							if(c[k-1]==j) b[i][j][k]=min(b[i][j][k],d[k-1][1]);
								else b[i][j][k]=min(b[i][j][k],d[k-1][0]);
						}
						else{
							b[i][j][k]=ma;
						}
					}
				}
			for(int k=0;k<=l;k++){
				while(!Q.empty()) Q.pop();
				Q.push(Node(ma,-1));
				Q.push(Node(ma,-1));
				for(int j=0;j<=m;j++){
					Q.push(Node(b[i][j][k],j));
					Q.pop();
				}
				Node tmp=Q.top();
				Q.pop();
				d[k][1]=tmp.x;
				tmp=Q.top();
				Q.pop();
				c[k]=tmp.y;
				d[k][0]=tmp.x;
			}
		}
		/*
		for(int i=0;i<=n;i++)
			for(int j=0;j<=m;j++)
				for(int k=0;k<=l;k++)
					printf("%d %d %d %lld\n",i,j,k,b[i][j][k]);
		*/
		long long ans=ma;
		for(int i=0;i<=m;i++)
			ans=min(b[n][i][l],ans);
		if(ans==ma) puts("-1");
			else printf("%lld\n",ans);
	}
}
