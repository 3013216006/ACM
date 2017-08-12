#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int vis[110][110];
int xx[10],yy[10];
char s[110][110];
int n,m;
int pan(int x,int y){
	if(x<0||y<0) return -1;
	if(x>=n||y>=m) return -1;
	if(s[x][y]=='0') return 0;
	return 1;
}

void dfs1(int i,int j){
	int x,y;
	vis[i][j]=1;
	for(int i1=0;i1<4;i1++){
		x=i+xx[i1];
		y=j+yy[i1];
		if(pan(x,y)==1&&!vis[x][y]) dfs1(x,y); 
	}
}

int dfs2(int i,int j){
	int x,y;
	vis[i][j]=1;
	int ret=1;
	for(int i1=0;i1<4;i1++){
		x=i+xx[i1];
		y=j+yy[i1];
		if(pan(x,y)==0&&!vis[x][y]) if(dfs2(x,y)==0) ret=0;
		if(pan(x,y)==-1) ret=0;
	}
	return ret;
}

int main(){
	xx[0]=0,yy[0]=1;
	xx[1]=1,yy[1]=0;
	xx[2]=0,yy[2]=-1;
	xx[3]=-1,yy[3]=0;
	while(~scanf("%d%d",&n,&m)){
		for(int i=0;i<n;i++)
			scanf("%s",s[i]);
		memset(vis,0,sizeof(vis));
		int ans=0,tmp=0;
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
			if(!vis[i][j]){
				if(s[i][j]=='1'){
					ans++;
					dfs1(i,j);
				}
				else{
					if(dfs2(i,j)==1) tmp++;
				}
			}
		if(ans==1){
			if(tmp==1) puts("0");
			else if(tmp==0) puts("1");
			else puts("-1");
		}
		else puts("-1");
	}
}
