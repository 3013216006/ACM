#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
using namespace std;
struct Edge{
	int num,next,v;
}edge[300000];
int head[1314*5],cnt;

void add(int x,int y,int v){
	//cout << x << " " << y << " " << v << endl;
	edge[cnt].num=y;
	edge[cnt].next=head[x];
	edge[cnt].v=v;
	head[x]=cnt++;
}

int getl(char s){
	if(s=='L') return 0;
	if(s=='O') return 1;
	if(s=='V') return 2;
	if(s=='E') return 3;
}

struct Node{
	int x;
	long long y;
	Node(){}
	Node(int _x,long long _y){
		x=_x,y=_y;
	}
	friend bool operator<(Node a,Node b){
		return a.y>b.y;
	}
};
priority_queue<Node> Q;
int vis[1314*5],len[1314*5];
long long dis[1314*5];
int getans(int s,int n){
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	memset(len,0,sizeof(len));
	long long tt=dis[0];
	dis[s]=0;
	len[s]=0;
	while(!Q.empty()) Q.pop();
	Q.push(Node(s,0));
	int flag=0;
	for(int i=0;i<=n+1;i++){
		while(!Q.empty()&&vis[Q.top().x]) Q.pop();
		if(Q.empty()) break;
		Node tmp=Q.top();
		Q.pop();
		int x=tmp.x;
		long long y=tmp.y;
		for(int i=head[x];i!=-1;i=edge[i].next){
			int v=edge[i].num;
			if(y+edge[i].v<dis[v]){
				dis[v]=y+edge[i].v;
				len[v]=len[x]+1;
				Q.push(Node(v,dis[v]));
			}
			else if(y+edge[i].v==dis[v]){
				len[v]=max(len[v],len[x]+1);
			}
		}
		if(x==0){
			if(flag) vis[x]=1;
			else flag=1,dis[0]=tt;
		}
		else vis[x]=1;
	}
	if(vis[n-4]) 
		return 1;
	else return 0;
}

int main(){
	int T,x,y,v,cas=1;
	int n,m;
	char s[10];
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		memset(head,-1,sizeof(head));
		cnt=0;
		for(int i=0;i<m;i++){
			scanf("%d%d%d%s",&x,&y,&v,s);
			int l=getl(s[0]),r=(l+1)%4;
			add(x*4-4+l,y*4-4+r,v);
			add(y*4-4+l,x*4-4+r,v);
		}
	//	if(n==1){
	//		printf("Case %d: Binbin you disappoint Sangsang again, damn it!\n",cas++);
	//		continue;
	//	}
		if(getans(0,n*4)){
			printf("Case %d: Cute Sangsang, Binbin will come with a donkey after travelling %lld meters and finding %d LOVE strings at last.\n",cas++,dis[n*4-4],len[n*4-4]/4);
		}
		else printf("Case %d: Binbin you disappoint Sangsang again, damn it!\n",cas++);
	}
}
