#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
struct Node{
	int v,next;
}edge[100010];
int ct;
int head[100010];
void add(int x,int y){
	edge[ct].next=head[x];
	edge[ct].v=y;
	head[x]=ct++;
}

priority_queue<int> Q;
int in[100010];
int ans[100010];
int main(){
	int n,m;
	int x,y;
	scanf("%d%d",&n,&m);
	memset(in,0,sizeof(in));
	memset(head,-1,sizeof(head));
	ct=0;
	for(int i=0;i<m;i++){
		scanf("%d%d",&x,&y);
		add(y,x);
		in[x]++;
	}
	for(int i=1;i<=n;i++)
		if(in[i]==0) Q.push(i);
	memset(ans,0,sizeof(ans));
	int cnt=n;
	while(!Q.empty()){
		int t=Q.top();
		ans[t]=cnt--;
		Q.pop();
		for(int i=head[t];i!=-1;i=edge[i].next){
			int v=edge[i].v;
			in[v]--;
			if(!in[v]) Q.push(v);
		}
	}
	for(int i=1;i<n;i++)
		printf("%d ",ans[i]);
	printf("%d\n",ans[n]);

}
