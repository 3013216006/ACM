#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
using namespace std;
struct Node{
	int num,next;
	char v;
}edge[1000010];
struct Node1{
	int x,y,z;
	Node1(){}
	Node1(int _x,int _y,int _z){
		x=_x,y=_y,z=_z;
	}
	friend bool operator <(const Node1 &a,const Node1 &b){
		return a.x>b.x;
	}
};
int anss,anse,cnt;
int head[500010];
int l;
char s[500010];
int dp[500010][2],fa[500010][2];
void add(int x,int y,char v){
	//cout << x << " " << y << " " << v << endl;
	edge[cnt].num=y;
	edge[cnt].next=head[x];
	edge[cnt].v=v;
	head[x]=cnt++;
	edge[cnt].next=head[y];
	edge[cnt].num=x;
	edge[cnt].v=v;
	head[y]=cnt++;
}
priority_queue<Node1> Q1;
priority_queue<Node1> Q2;
void dfs(int x,int f){
	for(int i=head[x];i!=-1;i=edge[i].next){
		int v=edge[i].num;
		if(v==f) continue;
		dfs(v,x);
	}
	while(!Q1.empty()) Q1.pop();
	while(!Q2.empty()) Q2.pop();
	Q1.push(Node1(0,x,x));
	Q1.push(Node1(0,x,x));
	Q2.push(Node1(1-l,x,x));
	Q2.push(Node1(1-l,x,x));
	for(int i=head[x];i!=-1;i=edge[i].next){
		int v=edge[i].num;
		if(v==f)continue;
		if(dp[v][1]!=-1&&s[dp[v][1]]==edge[i].v) dp[v][1]--;
		Q2.push(Node1(-dp[v][1],fa[v][1],v));
		if(dp[v][0]!=l&&s[dp[v][0]]==edge[i].v) dp[v][0]++;
		Q1.push(Node1(dp[v][0],fa[v][0],v));
		Q1.pop();
		Q2.pop();
	}
	Node1 tmp2=Q2.top();
	Node1 tmp1=Q1.top();
	Q1.pop();
	Q2.pop();
	Node1 tmp=Q1.top();
	dp[x][0]=tmp.x;fa[x][0]=tmp.y;
	int fa1=tmp.z;
	if(tmp.x==l) anse=x,anss=tmp.y;
	tmp=Q2.top();
	int fa2=tmp.z;
	dp[x][1]=-tmp.x;fa[x][1]=tmp.y;
	if(-tmp.x==-1) anss=x,anse=tmp.y;
	for(int i=head[x];i!=-1;i=edge[i].next){
		int v=edge[i].num;
		if(v==f)continue;
		if(fa1==v){
			if(tmp1.x>dp[v][1]){
				anse=fa[v][1];
				anss=tmp1.y;
			}
		}
		else{
			if(dp[x][0]>dp[v][1]){
				anss=fa[x][0];
				anse=fa[v][1];
			}
		}
		if(fa2==v){
			if(-tmp2.x<dp[v][0]){
				anss=fa[v][0];
				anse=tmp2.y;
			}
		}
		else{
			if(dp[x][1]<dp[v][0]){
				anss=fa[v][0];
				anse=fa[x][1];
			}
		}
	}
}

int main(){
	int n,m,x,y;
	while(~scanf("%d%d",&n,&m)){
		memset(head,-1,sizeof(head));
		cnt=0;
		for(int i=1;i<n;i++){
			scanf("%d%d%s",&x,&y,s);
			add(x,y,s[0]);
		}
		scanf("%s",s);
		l=strlen(s);
		anss=-1,anse=-1;
		dfs(1,0);
		/*
		for(int i=1;i<=n;i++)
			cout << dp[i][0] << " " << fa[i][0] << endl;
		cout << endl;
		for(int i=1;i<=n;i++)
			cout << dp[i][1] << " " << fa[i][1] << endl;
			*/
		cout << anss << " " << anse << endl;
	}
}
