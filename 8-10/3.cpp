#include <iostream>
#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;
struct Node1{
	int num,next,v,t;
}edge[20200];
struct Node{
	int num,x,y;
	friend bool operator<(const Node &a,const Node &b){
		if(a.x==b.x) return a.y>b.y;
		return a.x>b.x;
	}
};
priority_queue<Node>Q;
int head[120],cnt;
void add(int x,int y,int v,int t){
	edge[cnt].next=head[x];
	edge[cnt].num=y;
	edge[cnt].v=v;
	edge[cnt].t=t;
	head[x]=cnt++;
}
int vis[120];
int main(){
	int T,x,y,v,t;
	scanf("%d",&T);
	while(T--){
		int n,m;
		scanf("%d%d",&n,&m);
		memset(head,-1,sizeof(head));
		cnt=0;
		for(int i=0;i<m;i++){
			scanf("%d%d%d%d",&x,&y,&v,&t);
			add(x,y,v,t);
			add(y,x,v,t);
		}
		memset(vis,0,sizeof(vis));
		Node tmp;
		scanf("%d%d",&x,&y);
		tmp.num=x;
		tmp.x=0;
		tmp.y=0;
		while(!Q.empty()) Q.pop();
		Q.push(tmp);
		int ans=-1;
		while(!Q.empty()){
			tmp=Q.top();
			Q.pop();
			if(tmp.num==y){
				ans=0;
				break;
			}
			if(vis[tmp.num]==1) continue;
			vis[tmp.num]=1;
			//cout << tmp.num << endl;
			for(int i=head[tmp.num];i!=-1;i=edge[i].next){
				int v=edge[i].num;
				if(vis[v]==0){
					Node haha;
					haha.num=v;
					haha.x=tmp.x;
					haha.y=tmp.y;
					if(edge[i].t==1){
						haha.x+=edge[i].v;
					}
					haha.y+=edge[i].v;
					Q.push(haha);
				}
			}
		}
		if(ans==-1){
			puts("-1");
		}
		else{
			printf("%d %d\n",tmp.x,tmp.y);
		}
	}
}
