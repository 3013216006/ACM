#include <stdio.h>
#include <stack>
#include <math.h>
#include <string.h>
#include <iostream>
#include <queue>
using namespace std;

const int N = 10000;
const int M = 200000;
const int INF = 0x3f3f3f3f;
/*struct Edge
{
	int to,next,cap,flow;
	double cost;
}edge[MAXM];
int head[MAXN],tol;
int pre[MAXN];
double dis[MAXN];
bool vis[MAXN];
int N;//节点总个数,节点编号从0~N-1
void init(int n){
	N = n;
	tol = 0;
	memset(head,-1,sizeof(head));
}
void add(int u,int v,int cap,double cost){
	edge[tol].to = v;
	edge[tol].cap = cap;
	edge[tol].cost = cost;
	edge[tol].flow = 0;
	edge[tol].next = head[u];
	head[u] = tol++;
	edge[tol].to = u;
	edge[tol].cap = 0;
	edge[tol].cost = -cost;
	edge[tol].flow = 0;
	edge[tol].next = head[v];
	head[v] = tol++;
}
bool spfa(int s,int t){
	queue<int>q;
	for(int i = 0;i < N;i++){
		dis[i] = 1e200;
		vis[i] = false;
		pre[i] = -1;
	}
	dis[s] = 0;
	vis[s] = true;
	q.push(s);
	while(!q.empty()){
		int u = q.front();
		q.pop();
		vis[u] = false;
		for(int i = head[u]; i != -1;i = edge[i].next){
			int v = edge[i].to;
			if(edge[i].cap > edge[i].flow &&
			dis[v] > dis[u] + edge[i].cost+1e-7 ){
				dis[v] = dis[u] + edge[i].cost;
				pre[v] = i;
				if(!vis[v]){
					vis[v] = true;
					q.push(v);
				}
			}
		}
	}
	if(pre[t] == -1)return false;
	else return true;
}
//返回的是最大流,cost存的是最小费用
int minCostMaxflow(int s,int t,double &cost)
{
	int flow = 0;
	cost = 0;
	while(spfa(s,t)){
		int Min = INF;
		for(int i = pre[t];i != -1;i = pre[edge[i^1].to]){
			if(Min > edge[i].cap - edge[i].flow)
			Min = edge[i].cap - edge[i].flow;
		}
		for(int i = pre[t];i != -1;i = pre[edge[i^1].to]){
			edge[i].flow += Min;
			edge[i^1].flow -= Min;
			cost += edge[i].cost * Min;
		}
		flow += Min;
	}
	return flow;
}
*/
struct Node {
int fe, ln, le; //ln 上一个点,le 上一条边,c 为 s 到当前点最小花费
double c;
bool d; //是否在队列内
};
struct Edge {
int f, t, ne;
double c;
};
Node a[N];
Edge b[M * 2];
int s, t, n, p, flow;
double cost;
void clear(int nn, int ss, int tt) {
n = nn; s = ss; t = tt;
for (int i = 0; i < n; i++) a[i].fe = -1;
p  = flow = 0;
cost=0;
}
void putedge(int x, int y, int f, double  c) {
b[p].ne = a[x].fe; b[p].t = y; b[p].f = f; b[p].c = c; a[x].fe = p++;
b[p].ne = a[y].fe; b[p].t = x; b[p].f = 0; b[p].c = -c; a[y].fe = p++;
}
inline int add(int &p) {
int ans = p++;
if (p == N) p = 0;
return ans;
}
bool spfa() {
static int d[N];
for (int i = 0; i < n; i++) {
a[i].c = 1e150;
a[i].ln = a[i].le = -1;
a[i].d = false;
}
int p = 0, q = 0;
d[add(q)] = s;
a[s].d = true;
a[s].c = 0;
while (p != q) {
int u = d[add(p)];
for (int j = a[u].fe; j != -1; j = b[j].ne) {
int v = b[j].t;
if (b[j].f > 0 && b[j].c + a[u].c < a[v].c-1e-8) {
a[v].c = a[u].c + b[j].c;
a[v].ln = u;
a[v].le = j;
if (a[v].d == false) {
a[v].d = true;
d[add(q)] = v;
}
}
}
a[u].d = false;
}
if (a[t].c >1e149) return false;
p = INF;
q = 0;
for (int i = t; i != s; i = a[i].ln) {
d[q++]=i;
if (p > b[a[i].le].f) p = b[a[i].le].f;
}
flow += p;
for (int i = q - 1; i >= 0; i--) {
int j = a[d[i]].le;
cost += b[j].c * p;
b[j].f -= p;
b[j ^ 1].f += p;
}
return true;
}
void minCostFlow() {
while (spfa());
}
int main(){
	int T,x,y,z,n,m;
	double c;
	scanf("%d",&T);
	while(T--){
		int s=0,t;
		scanf("%d%d",&n,&m);
		t=n+1;
		int N=n+2;
		//init(N);
		clear(N,s,t);
		for(int i=1;i<=n;i++){
			scanf("%d%d",&x,&y);
			if(x>y) putedge(s,i,x-y,0);
				else if(y>x) putedge(i,t,y-x,0);
		}
		for(int i=0;i<m;i++){
			scanf("%d%d%d%lf",&x,&y,&z,&c);
			putedge(x,y,1,0);
			if(z>1) putedge(x,y,z-1,-log(1.0-c));
		}
		//NV=n+2;S=0,T=n+1;
		//minCostMaxflow(s,t,cost);
		minCostFlow();
		//double cost=fee_flow;
		cost=exp(-cost);
		cost=1.0-cost;
		printf("%.2f\n",cost);
	}
}

