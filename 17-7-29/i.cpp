#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
queue<pair<int,int> > Q;
	int n,m,a,b;
struct Node{
	int v,next;
}edge[1000001];
int cnt,head[100001],x,y;
void add(int x,int y){
	edge[cnt].v=y;
	edge[cnt].next=head[x];
	head[x]=cnt++;
	edge[cnt].v=x;
	edge[cnt].next=head[y];
	head[y]=cnt++;
}
int vis[100010];
int getans(int st,int a,int b){
	memset(vis,0,sizeof(vis));
	while(!Q.empty()) Q.pop();
	Q.push(make_pair(st,0));
	vis[st]=1;
	while(!Q.empty()){
		pair<int,int> tmp=Q.front();
		Q.pop();
		if(tmp.first==n) return tmp.second;
		if(tmp.second+a>=b) return b;
		for(int i=head[tmp.first];i!=-1;i=edge[i].next){
			int v=edge[i].v;
			if(!vis[v]){
				Q.push(make_pair(v,tmp.second+a));
				vis[v]=1;
			}
		}
	}
	return b;
}

vector<int> v;
queue<int> Q1;
int getdis(int st,int a,int b){
	memset(vis,0,sizeof(vis));
	v.clear();
	while(!Q1.empty()) Q1.pop();
	for(int i=2;i<=n;i++)
		Q1.push(i);
	v.push_back(st);
	for(int i=b;i<a;i+=b){
		if(v.size()==0) return a;
		for(int j=0;j<v.size();j++){
			for(int k=head[v[j]];k!=-1;k=edge[k].next){
				int V=edge[k].v;
				vis[V]++;
			}
		}
		int x=Q1.size(),y=v.size();
		v.clear();
		for(int j=0;j<x;j++){
			int tmp=Q1.front();
			Q1.pop();
			if(vis[tmp]==y) {
				Q1.push(tmp);
				vis[tmp]=0;
			}
			else{
				v.push_back(tmp);
				if(tmp==n) return i;
			}

		}
	}
	return a;
}
int main(){
	while(~scanf("%d%d%d%d",&n,&m,&a,&b)){
		int flag=0;
		memset(head,-1,sizeof(head));
		cnt=0;
		for(int i=0;i<m;i++){
			scanf("%d%d",&x,&y);
			add(x,y);
			if(x>y) swap(x,y);
			if(x==1&&y==n) flag=1;
		}
		if (flag) {
			if(a<=b){
				printf("%d\n",a);
				continue;
			}
			else{
				cout <<	getdis(1,a,b) << endl;
			}
		}
		else{
			if(b<=a){
				printf("%d\n",b);
				continue;
			}
			else{
				cout << getans(1,a,b) << endl;
			}
		}

	}
}
