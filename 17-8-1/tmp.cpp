#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll maxn = 1e6 + 10;
struct Edge{
    ll u;
    ll v;
    ll w;
}edges[maxn * 2];
vector<ll> G[maxn];
ll ans,n,k,a,b,c;
ll siz[maxn],vis[maxn];
void dfs(ll fa){
    vis[fa] = 1;
    siz[fa] = 1;
    for(ll i = 0;i < G[fa].size();i++){
        Edge & e = edges[G[fa][i]];
        ll v = e.v;
        if(vis[v] == 1) continue;
        dfs(v);
        siz[fa] += siz[v];
        ans += min(siz[v],k) * e.w;
    }
}
    
int main()
{
    while(~scanf("%lld%lld",&n,&k)){
        ans = 0;
        for(ll i = 1;i <= n;i++) G[i].clear();
        memset(vis,0,sizeof(vis));
        for(ll i = 1;i < n;i++){
            scanf("%lld%lld%lld",&a,&b,&c);
            edges[i].u = a;
            edges[i].v = b;
            edges[i].w = c;
            G[a].push_back(i);
            edges[i + n].v = a;
            edges[i + n].u = b;
            edges[i + n].w = c;
            G[b].push_back(i + n);
        }
        dfs(1);
        printf("%lld\n",ans);
    }
    return 0;
}
            
