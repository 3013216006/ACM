#include <iostream>
#include <stdio.h>
#include <queue>
#include <string.h>
using namespace std;
struct Node{
	int x,y;
	friend bool operator<(const Node &a,const Node &b){
		if(a.y==b.y) return a.x>b.x;
		return a.y<b.y;
	}
};
priority_queue<Node> Q;
int vis[500200];
int main(){
	int T,n,s,p;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&s,&p);
		while(!Q.empty()) Q.pop();
		printf("%d",s);
		Node tmp;
		memset(vis,0,sizeof(vis));
		vis[s]=1;
		if(s/2) {
			tmp.x=s/2,tmp.y=s-tmp.x;
			tmp.y%=p;
			Q.push(tmp);
			vis[tmp.x]=1;
		}
		if(s<<1<=n){
			tmp.x=s<<1,tmp.y=tmp.x-s;
			tmp.y%=p;
			Q.push(tmp);
			vis[tmp.x]=1;
		}
		if(((s<<1)|1)<=n){
			tmp.x=(s<<1)+1,tmp.y=tmp.x-s;
			tmp.y%=p;
			Q.push(tmp);
			vis[tmp.x]=1;
		}
		while(!Q.empty()){
			Node t=Q.top();
			Q.pop();
			printf(" %d",t.x);
			s=t.x;
		if(t.x/2) if(vis[s/2]==0){
			
			tmp.x=s/2,tmp.y=s-tmp.x;
			tmp.y%=p;
			Q.push(tmp);
			vis[tmp.x]=1;
		}
		if(s<<1<=n)if(vis[s<<1]==0){
			tmp.x=s<<1,tmp.y=tmp.x-s;
			tmp.y%=p;
			Q.push(tmp);
			vis[tmp.x]=1;
		}
		if(((s<<1)|1)<=n)if(vis[(s<<1)+1]==0){
			tmp.x=(s<<1)+1,tmp.y=tmp.x-s;
			tmp.y%=p;
			Q.push(tmp);
			vis[tmp.x]=1;
		}
		}
		puts("");
	}
}
