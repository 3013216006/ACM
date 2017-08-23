#include <iostream>
#include <stdio.h>
#include <queue>
#include <map>
#include <algorithm>
#include <string.h>
using namespace std;
struct Node{
	int x,y;
	long long v;
	Node(){}
	Node(int _x,int _y,long long _v){
		x=_x,y=_y,v=_v;
	}
	friend bool operator<(Node a,Node b){
		return a.v>b.v;
	}
};
map<int,int> M[100010];
map<int,long long> M1[100010];
priority_queue<Node> Q;
long long d[100010];
int head[100100],vis[100010];
int cnt;
bool _is[100100];
struct Edge{
	int v,next,num;
}edge[200010];

void add(int x,int y,int v){
	edge[cnt].next=head[x];
	edge[cnt].v=v;
	edge[cnt].num=y;
	head[x]=cnt++;
}

int main(){
	int T,cas=1;
	int n,m,x,y,v;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		memset(head,-1,sizeof(int)*(n+1));
		cnt=0;
		for(int i=0;i<m;i++){
			scanf("%d%d%d",&x,&y,&v);
			add(x,y,v);
		}
		int k;
		scanf("%d",&k);
		while(!Q.empty()) Q.pop();
		memset(d,0x3f,sizeof(int)*(n+1));
		memset(_is,0,sizeof(_is));
		for(int i=0;i<k;i++){
			scanf("%d",&x);
			d[x]=0;
			_is[x]=1;
			Q.push(Node(x,x,0));
		}
		memset(vis,0,sizeof(vis));
		long long ans=-1;
		while(!Q.empty()){
			Node t=Q.top();
			Q.pop();
			if(M[t.x].count(t.y)) continue;
			M[t.x][t.y]=1;
			if(ans!=-1&&t.v>=ans) break;
			if(_is[t.x]&&t.x!=t.y){
				ans=t.v;
				break;
			}
			else{
				if(vis[t.x]==2) continue;;

				vis[t.x]++;
			}
			for(int i=head[t.x];i!=-1;i=edge[i].next){
					int v=edge[i].num;
					if(M1[v].count(t.y)==0){
						long long tp=t.v+edge[i].v;
						M1[v][t.y]=tp;
						Q.push(Node(v,t.y,tp));
					}
					else{
						long long tp=t.v+edge[i].v;
						if(tp<M1[v][t.y]){
							Q.push(Node(v,t.y,tp));
							M1[v][t.y]=tp;
						}
					}
				}
		}
		for(int i=1;i<=n;i++) M[i].clear(),M1[i].clear();
		printf("Case #%d: %lld\n",cas++,ans);
	}
}
