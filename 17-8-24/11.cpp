#include <iostream>
#include <string.h>
#include <stdio.h>
#include <queue>
#include <algorithm>
using namespace std;
struct Node{
	int x;
	long long d;
	Node(){}
	Node(int _x,long long _d){
		x=_x,d=_d;
	}
	friend bool operator<(Node a,Node b){
		return a.d>b.d;
	}
};

struct Node1{
	int num,next;
	long long d;
}edge[200010];

int head[100010],cnt,vis[100010];
long long d[100010];

void add(int x,int y,int d){
	edge[cnt].num=y;
	edge[cnt].next=head[x];
	edge[cnt].d=d;
	head[x]=cnt++;
	edge[cnt].num=x;
	edge[cnt].next=head[y];
	edge[cnt].d=d;
	head[y]=cnt++;
}
priority_queue<Node> Q;

int main(){
	int T;
	int n,m;
	int x,y,z;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		memset(head,-1,sizeof(head));
		cnt=0;
		for(int i=0;i<m;i++){
			scanf("%d%d%d",&x,&y,&z);
			add(x,y,z);
		}
		memset(vis,0,sizeof(vis));
		while(!Q.empty()) Q.pop();
		Q.push(Node(1,0));
		while(!Q.empty()){
			Node tmp=Q.top();
			Q.pop();
			vis[tmp.x]++;
			d[tmp.x]=tmp.d;
			if(vis[n]==2) break;
			if(vis[tmp.x]>2) continue;
			for(int i=head[tmp.x];i!=-1;i=edge[i].next){
				int v=edge[i].num;
				if(vis[v]<2){
					Q.push(Node(v,tmp.d+edge[i].d));
				}
			}
		}
		if(vis[n]==2) printf("%lld\n",d[n]);
		else puts("-1");
	}
}
