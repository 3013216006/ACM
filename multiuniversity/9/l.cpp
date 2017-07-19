#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
const int M=50000;
struct Node1{
	int x,y,id;
}a[210];
vector<int> V[210];
int c[210],d[210];

bool cmp(Node1 a,Node1 b){
	return a.y<b.y;
}
const int mn=300;
const int mm=42222;
const int oo=1e9;
int node, st, sd, edge;
int ver[mm], flow[mm], _next[mm];
int head[mn], work[mn], dis[mn], q[mn], visit[mn];

inline void init(int _node, int _st, int _sd)
{
    node=_node, st=_st, sd=_sd;
    for(int i=0; i<node; i++)
        head[i]=-1;
    edge=0;
}

void add(int u, int v, int c1, int c2)
{
//	cout << u << " " << v << " " << c1 << " " << c2 << endl;
    ver[edge]=v, flow[edge]=c1, _next[edge]=head[u],head[u]=edge++;
    ver[edge]=u, flow[edge]=c2, _next[edge]=head[v],head[v]=edge++;
}
bool Dinic_bfs()
{
    int i,u,v,l,r=0;
    for(i=0; i<node; ++i)dis[i]=-1;
    dis[q[r++]=st]=0;
    for(l=0; l<r; ++l)
        for(i=head[u=q[l]]; i>=0; i=_next[i])
            if(flow[i]&&dis[v=ver[i]]<0)
            {
                dis[q[r++]=v]=dis[u]+1;
                if(v==sd)return 1;
            }
    return 0;
}
long long Dinic_dfs(int u, int exp)
{
    if(u==sd) return exp;
    for(int &i=work[u]; i>=0; i=_next[i])
    {
        int v=ver[i], tp;
        if(flow[i]&&dis[v]==dis[u]+1&&(tp=Dinic_dfs(v,min(flow[i],exp)))>0)
        {
            flow[i]-=tp;
            flow[i^1]+=tp;
            return tp;
        }
    }
    return 0;
}
long long Dinic_flow()
{
    int i,delta;
    long long ret=0;
    while(Dinic_bfs())
    {
        for(i=0; i<node; ++i)work[i]=head[i];
        while(delta=Dinic_dfs(st,oo))ret+=delta;
    }
    return ret;
}

void DFS(int u)
{
    visit[u]=1;
    for(int i=head[u], v; i>=0; i=_next[i])
        if(flow[i]>0&&!visit[v=ver[i]]) DFS(v);
}

int main()
{
    int T,n,m,l,x,y,cas=1;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&m,&l);
		int S,T;
		S=0;T=n+m+1;
		for(int i=1;i<=n;i++){
			scanf("%d%d",&a[i].x,&a[i].y);
			a[i].id=i;
		}
		int mytmp=0;
		for(int i=1;i<=m;i++){
			scanf("%d",&c[i]);
			V[i].clear();
			scanf("%d",&x);
			d[i]=0;
			for(int j=0;j<x;j++){
				scanf("%d",&y);
				V[i].push_back(y);
				d[i]=max(d[i],a[y].y);
			}
			if(x==0) mytmp+=c[i];
		}
		if(mytmp>=l){
			printf("Case #%d: 0 %d\n",cas++,mytmp);
			continue;
		}
		sort(a+1,a+1+n,cmp);
		int ans=0,anst=-1;
		for(int i=1;i<=n;i++){
		//	cout << i << endl;
			if(i<n&&a[i].y==a[i+1].y) continue;
			init(T+1,S,T);
			for(int j=1;j<=i;j++)
				add(a[j].id,T,a[j].x,0);
				int sum=0;
			for(int j=1;j<=m;j++)
				if(d[j]<=a[i].y){
					add(S,j+n,c[j],0);sum+=c[j];
					for(int k=0;k<V[j].size();k++)
						add(j+n,V[j][k],oo,0);
				}	

		//	cout << "haha\n" ;
			long long maxflow=Dinic_flow();
			memset(visit,0,sizeof(visit));
        		DFS(st);
        		maxflow=sum-maxflow;
		//	cout << maxflow << endl;
			if(maxflow>=l){
				ans=(int)maxflow;
				anst=a[i].y;
				break;
			}
		}
		printf("Case #%d: ",cas++);
		if(ans<l) puts("impossible");
		else printf("%d %d\n",anst,ans);
	}
    return 0;
}
