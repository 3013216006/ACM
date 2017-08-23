#include <iostream>
using namespace std;
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
	edge[tot].next[head]=head[u];
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
	if(LOW[u] == DFN[u]){
		scc++;
		do{
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
	for(int i=1;i<N;i++)
		if(!DFN[i])
			Tarjan(i);
}
void init(){
	tot=0;
	memset(head,-1,sizeof(head);
}


int main(){

}
