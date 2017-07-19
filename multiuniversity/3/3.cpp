#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int kn[1100][1100],k[1100][1100],kx[10],ky[10],knx[10],kny[10];
int q[2100],n,m,t;
int dfsking(int x,int y){
	if(k[x][y]) return k[x][y];
	for(int i=0;i<3;i++){
		int tmpx=x+kx[i];
		int tmpy=y+ky[i];
		if(tmpx>0&&tmpy>0)
			if(dfsking(tmpx,tmpy)==-1) return k[x][y]=1;
	}
	return k[x][y]=-1;
}

int dfskn(int x,int y){
	if(kn[x][y]) return kn[x][y];
	for(int i=0;i<2;i++){
		int tmpx=x+knx[i];
		int tmpy=y+kny[i];
		if(tmpx>0&&tmpy>0){
			int ans=dfskn(tmpx,tmpy);
			if(ans==1) return kn[x][y]=3;
			if(ans==3&&kn[x][y]==0) kn[x][y]=1;
			if(ans==2) kn[x][y]=2;
		}
	}
	if(kn[x][y]!=0) return kn[x][y];
		else return kn[x][y]=2;
}

void init(){
	kx[0]=-1;ky[0]=-1;
	kx[1]=-1;ky[1]=0;
	kx[2]=0;ky[2]=-1;
	knx[0]=-1;kny[0]=-2;
	knx[1]=-2;kny[1]=-1;
}

int main(){
	int d=0;
	init();
	memset(q,0,sizeof(q));
	for(int i=1;i<=1000;i++)
		if(!q[i]){
			q[i]=i+d;
			q[d+i]=i;
			d++;
		}
	memset(k,0,sizeof(k));
	k[1][1]=-1;
	dfsking(1000,1000);
	memset(kn,0,sizeof(kn));
	kn[1][1]=1;
	for(int i=1;i<=1000;i++)
		for(int j=1;j<=1000;j++)
			if(kn[i][j]==0)
				dfskn(i,j);
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&t,&n,&m);
		if(t==1){
			if(k[n][m]==1) puts("B");
			else puts("G");
		}
		else if(t==2){
			if(n==m) puts("G");
				else puts("B");
		}
		else if(t==3){
			if(kn[n][m]==3) puts("B");
				else if(kn[n][m]==2) puts("D");
					else puts("G");
		}
		else{
			if(q[n]==m) {
				puts("G");
				continue;
			}
			else puts("B");
		}
	}
}
