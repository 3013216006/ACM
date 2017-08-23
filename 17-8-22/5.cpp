#include <iostream>
#include <stdio.h>
#include <string.h>
#include <map>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
queue<int> Q;
vector<int> v[1100],v1[1100];
map<pair<int,int>,int > M;

int fa[1100],in[1100];

int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
const int MAXN = 20001;
const int MAXM = 60000;

struct Edge{
	int to,next;
}edge[MAXM];
int head[MAXN],tot;
int Low[MAXN],DFN[MAXN],Stack[MAXN],Belong[MAXN];
int Index,top;
int scc;

bool Instack[MAXN];
int num[MAXN];

void addedge(int u,int v){
	edge[tot].to = v;
	edge[tot].next=head[u];
	head[u]=tot++;
}

int flag=1;
void Tarjan(int u){
	int v;
	Low[u]=DFN[u]=++Index;
	Stack[top++]=u;
	Instack[u]=true;
	int x=0;
	for(int i=head[u];i!=-1;i=edge[i].next){
		v=edge[i].to;
		if(!DFN[v]){
			Tarjan(v);
			if(Low[u]>Low[v]) Low[u]=Low[v];
			else x++;
		}
		else if(Instack[v]&&Low[u]>DFN[v])
			Low[u]=DFN[v];
	}
	if(Low[u] == DFN[u]){
		scc++;
		do{
			v1[scc].clear();
			v=Stack[--top];
			Instack[v] = false;
			Belong[v]=scc;
			num[scc]++;
		}
		while(v!=u);
	}
	if(x>1) flag=0;
}

void solve(int N){
	memset(DFN,0,sizeof(DFN));
	memset(Instack,false,sizeof(Instack));
	memset(num,0,sizeof(num));
	Index=scc=top=0;
	int x=0;
	for(int i=1;i<N;i++){
		if(!DFN[i])
			Tarjan(i),x++;
	}
	if(x>1) flag=0;
}
void init(){
	tot=0;
	memset(head,-1,sizeof(head));
}
int main(){
	int T;
	int x,y;
	scanf("%d",&T);
	while(T--){
		int n,m;
		scanf("%d%d",&n,&m);
		memset(in,0,sizeof(in));
		for(int i=1;i<=n;i++){
			fa[i]=i;
			v[i].clear();
		}
		init();
		for(int i=0;i<m;i++){
			scanf("%d%d",&x,&y);
			addedge(y,x);
			v[y].push_back(x);
			int fax=find(x),fay=find(y);
			fa[fax]=fay;
		}
		x=0;
		for(int i=1;i<=n;i++){
			if(fa[i]==i) x++;
		}
		if(x>1){
			puts("Light my fire!");
			continue;
		}

		solve(n+1);
		flag=1;
		while(!Q.empty()) Q.pop();
		M.clear();
		for(int i=1;i<=n&&flag;i++){
			for(int j=0;j<v[i].size();j++){
				int t=v[i][j];
				if(Belong[i]==Belong[t]) continue;
				if(M.count(make_pair(Belong[i],Belong[t]))>0) continue;
				M[make_pair(Belong[i],Belong[t])]=1;
				M[make_pair(Belong[t],Belong[i])]=1;
				in[Belong[i]]++;
				v1[Belong[t]].push_back(Belong[i]);
			}
		}
		for(int i=1;i<=scc;i++)
		if(in[i]==0) Q.push(i);
		int x=0;
		while(!Q.empty()){
			if(Q.size()>1){
				flag=0;
				break;
			}
			int t=Q.front();
			Q.pop();
			x++;
			for(int i=0;i<v1[t].size();i++){
				in[v1[t][i]]--;
				if(in[v1[t][i]]==0) Q.push(v1[t][i]);
			}
		}
		if(flag&&x==scc) puts("I love you my love and our love save us!");
		else puts("Light my fire!");

	}
}
