#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;
struct Node{
	int v,next;
	Node(){}
	Node(int _v,int _next){
		v=_v,next=_next;
	}
}edge[200001];
int l[200001],r[200001];
int ct;
int head[100001];
char s[10];
void addedge(int x,int y){
	edge[ct].v=y;
	edge[ct].next=head[x];
	head[x]=ct++;
	edge[ct].v=x;
	edge[ct].next=head[y];
	head[y]=ct++;
}
int cnt;
void dfs(int x,int fa){
	l[x]=cnt++;
	for(int i=head[x];i!=-1;i=edge[i].next){
		int v=edge[i].v;
		if(v==fa) continue;
		dfs(v,x);

	}
	r[x]=cnt++;
}
int t[200010];
int N;
int lowbit(int x){
	return x&(-x);
}
void add(int x,int op){
	while(x<=N){
		t[x]+=op;
		x+=lowbit(x);
	}
}
int query(int x){
	int ret=0;
	while(x){
		ret+=t[x];
		x-=lowbit(x);
	}
	return ret;
}
int _is[100001];
int main(){
	int n,x,y;
	scanf("%d",&n);
	N=n*2;
	ct=0;
	memset(head,-1,sizeof(head));
	for(int i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		addedge(x,y);
	}
	cnt=1;
	dfs(1,0);
	memset(t,0,sizeof(t));
	for(int i=1;i<=n;i++){
		add(l[i],1);
		_is[i]=1;
	}
	int m;
	scanf("%d",&m);
	for(int i=0;i<m;i++){
		scanf("%s%d",s,&x);
		if(s[0]=='Q'){
			printf("%d\n",query(r[x])-query(l[x]-1));
		}
		else{
			if(_is[x]){
				_is[x]=0;
				add(l[x],-1);
			}
			else{
				_is[x]=1;
				add(l[x],1);
			}
		}
	}
}
