#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

const int mn=5555;
const int mm=222222;
const int oo=1e9;
int node, st, sd, edge;
int ver[mm], flow[mm], next[mm];
int head[mn], work[mn], dis[mn], q[mn], visit[mn];

inline void init(int _node, int _st, int _sd)
{
    node=_node, st=_st, sd=_sd;
    for(int i=0; i<node; i++)
        head[i]=-1;
    edge=0;
}

void addedge(int u, int v, int c1, int c2)
{
	cout << u << " " << v << " " << c1 << " " << c2 << endl;
    ver[edge]=v, flow[edge]=c1, next[edge]=head[u],head[u]=edge++;
    ver[edge]=u, flow[edge]=c2, next[edge]=head[v],head[v]=edge++;
}
bool Dinic_bfs()
{
    int i,u,v,l,r=0;
    for(i=0; i<node; ++i)dis[i]=-1;
    dis[q[r++]=st]=0;
    for(l=0; l<r; ++l)
        for(i=head[u=q[l]]; i>=0; i=next[i])
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
    for(int &i=work[u]; i>=0; i=next[i])
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
    for(int i=head[u], v; i>=0; i=next[i])
        if(flow[i]>0&&!visit[v=ver[i]]) DFS(v);
}

int main()
{
    int n, m, w, u, v;
    while(~scanf("%d%d",&n,&m))
    {
        init(n+2,0,n+1);
        long long sum=0;
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&w);
            if(w>0) sum+=w,addedge(st,i,w,0);
            if(w<0)  addedge(i,sd,-w,0);;
        }
        while(m--)
        {
            scanf("%d%d",&u,&v);
            addedge(u,v,oo,0);
        }
        long long maxflow=Dinic_flow();
        memset(visit,0,sizeof(visit));
        DFS(st);
        int ans=0;
        for(int i=1; i<=n; i++) ans+=visit[i];
        printf("%d %lld\n",ans,(long long)(sum-maxflow));
    }
    return 0;
}
