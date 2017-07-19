/*
#include <iostream>
#include <stdio.h>
#include <queue>
#include <string.h>
#include <algorithm>
using namespace std;
char s1[200];
int vis[110][110][1<<4],a[110][110];
int n,m,k,x,y;
struct Node{
	int x,y,t,s;
}to[5],s;

int pan(Node a1){
	if(a1.x<0||a1.y<0) return 1;
	if(a1.x==n||a1.y==m) return 1;
	if(a[a1.x][a1.y]) return 0;
	return 1;
}

void init(){
	to[0].x=1;to[0].y=0;
	to[1].x=-1;to[1].y=0;
	to[2].x=0;to[2].y=1;
	to[3].x=0;to[3].y=-1;
}
queue<Node> Q;
int main(){
	init();
	while(~scanf("%d%d",&n,&m)){
		memset(a,0,sizeof(a));
		if(n==0&&m==0) break;
		for(int i=0;i<n;i++){
			scanf("%s",s1);
			for(int j=0;j<m;j++){
				if(s1[j]=='.') a[i][j]=1;
				if(s1[j]=='@'){
					a[i][j]=1;
					s.x=i;
					s.y=j;
					s.t=0;
				}
			}
		}
		scanf("%d",&k);
		for(int i=0;i<k;i++){
			scanf("%d%d",&x,&y);
			x--;y--;
			if(a[x][y]) a[x][y]=i+2;
		}
		while(!Q.empty())Q.pop();
		if(a[s.x][s.y]>1){
			s.t|=(1<<(a[s.x][s.y]-2));
		}
		s.s=0;
		Q.push(s);
		memset(vis,0,sizeof(vis));
		int ans=-1;
		int flag=1<<k;
		flag--;
		while(!Q.empty()&&ans==-1){
			s=Q.front();
			Q.pop();
			for(int i=0;i<4;i++){
				Node tmp;
				tmp.x=s.x+to[i].x;
				tmp.y=s.y+to[i].y;
				if(pan(tmp)) continue;
				tmp.t=s.t;
				if(a[tmp.x][tmp.y]>1){
					tmp.t|=(1<<(a[tmp.x][tmp.y]-2));
				}
				if(vis[tmp.x][tmp.y][tmp.t]==0){
					vis[tmp.x][tmp.y][tmp.t]=1;
					tmp.s=s.s+1;
					Q.push(tmp);
					if(tmp.t==flag){
						ans=tmp.s;
					}
				}
			}
		}
		printf("%d\n",ans);
	}
}
#include <iostream>
#include <stdio.h>
#include <queue>
#include <string.h>
#include <algorithm>
using namespace std;
char s1[200];
int vis[110][110][1<<4],a[110][110];
int n,m,k,x,y;
struct Node{
	int x,y,t,s;
}to[5],s;

int pan(Node a1){
	if(a1.x<0||a1.y<0) return 1;
	if(a1.x==n||a1.y==m) return 1;
	if(a[a1.x][a1.y]) return 0;
	return 1;
}

void init(){
	to[0].x=1;to[0].y=0;
	to[1].x=-1;to[1].y=0;
	to[2].x=0;to[2].y=1;
	to[3].x=0;to[3].y=-1;
}
queue<Node> Q;
int main(){
	init();
	while(~scanf("%d%d",&n,&m)){
		memset(a,0,sizeof(a));
		if(n==0&&m==0) break;
		for(int i=0;i<n;i++){
			scanf("%s",s1);
			for(int j=0;j<m;j++){
				if(s1[j]=='.') a[i][j]=1;
				if(s1[j]=='@'){
					a[i][j]=1;
					s.x=i;
					s.y=j;
					s.t=0;
				}
			}
		}
		scanf("%d",&k);
		for(int i=0;i<k;i++){
			scanf("%d%d",&x,&y);
			x--;y--;
			if(a[x][y]) a[x][y]=i+2;
		}
		while(!Q.empty())Q.pop();
		if(a[s.x][s.y]>1){
			s.t|=(1<<(a[s.x][s.y]-2));
		}
		s.s=0;
		Q.push(s);
		memset(vis,0,sizeof(vis));
		int ans=-1;
		int flag=1<<k;
		flag--;
		while(!Q.empty()&&ans==-1){
			s=Q.front();
			Q.pop();
			for(int i=0;i<4;i++){
				Node tmp;
				tmp.x=s.x+to[i].x;
				tmp.y=s.y+to[i].y;
				if(pan(tmp)) continue;
				tmp.t=s.t;
				if(a[tmp.x][tmp.y]>1){
					tmp.t|=(1<<(a[tmp.x][tmp.y]-2));
				}
				if(vis[tmp.x][tmp.y][tmp.t]==0){
					vis[tmp.x][tmp.y][tmp.t]=1;
					tmp.s=s.s+1;
					Q.push(tmp);
					if(tmp.t==flag){
						ans=tmp.s;
					}
				}
			}
		}
		printf("%d\n",ans);
	}
}
*/
#include <iostream>
#include <stdio.h>
#include <queue>
#include <string.h>
#include <algorithm>
using namespace std;
char s1[200];
int vis[110][110][1<<4],a[110][110];
int n,m,k,x,y;
struct Node{
	int x,y,t,s;
}to[5],s;

int pan(Node a1){
	if(a1.x<0||a1.y<0) return 1;
	if(a1.x==n||a1.y==m) return 1;
	if(a[a1.x][a1.y]) return 0;
	return 1;
}

void init(){
	to[0].x=1;to[0].y=0;
	to[1].x=-1;to[1].y=0;
	to[2].x=0;to[2].y=1;
	to[3].x=0;to[3].y=-1;
}
queue<Node> Q;
int main(){
	init();
	while(~scanf("%d%d",&n,&m)){
		memset(a,0,sizeof(a));
		if(n==0&&m==0) break;
		for(int i=0;i<n;i++){
			scanf("%s",s1);
			for(int j=0;j<m;j++){
				if(s1[j]=='.') a[i][j]=1;
				if(s1[j]=='@'){
					a[i][j]=1;
					s.x=i;
					s.y=j;
					s.t=0;
				}
			}
		}
		scanf("%d",&k);
		for(int i=0;i<k;i++){
			scanf("%d%d",&x,&y);
			x--;y--;
			if(a[x][y]) a[x][y]=i+2;
		}
		while(!Q.empty())Q.pop();
		if(a[s.x][s.y]>1){
			s.t|=(1<<(a[s.x][s.y]-2));
		}
		s.s=0;
		Q.push(s);
		memset(vis,0,sizeof(vis));
		int ans=-1;
		int flag=1<<k;
		flag--;
		while(!Q.empty()&&ans==-1){
			s=Q.front();
			Q.pop();
			for(int i=0;i<4;i++){
				Node tmp;
				tmp.x=s.x+to[i].x;
				tmp.y=s.y+to[i].y;
				if(pan(tmp)) continue;
				tmp.t=s.t;
				if(a[tmp.x][tmp.y]>1){
					tmp.t|=(1<<(a[tmp.x][tmp.y]-2));
				}
				if(vis[tmp.x][tmp.y][tmp.t]==0){
					vis[tmp.x][tmp.y][tmp.t]=1;
					tmp.s=s.s+1;
					Q.push(tmp);
					if(tmp.t==flag){
						ans=tmp.s;
					}
				}
			}
		}
		printf("%d\n",ans);
	}
}
