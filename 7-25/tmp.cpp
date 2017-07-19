#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;
typedef long long ll;

#define maxn 1010
#define inf 0x3f3f3f3f
int n, m, s, t, k, a, b, c;
vector < pair<int, int> > V[maxn];
int V2[maxn][maxn];

struct node{
    int d, u;
    bool operator < (const node& no) const {
        return d > no.d;
    }
};
struct nd{
    int f, h, g, num;
    bool operator < (const nd& no) const{
        return f > no.f;
    }
};

priority_queue<nd> q2;
int visit[maxn];
int _h[maxn];

void calc_h(int t){//dijkstra
    priority_queue<node> q;
    memset(_h, -1, sizeof _h);
    _h[t] = 0;
    memset(visit, 0, sizeof visit);
    q.push((node){0, t});
    while(!q.empty()){
        node no = q.top();
        q.pop();
        int u = no.u;
        if(visit[u]) continue;
        visit[u] = true;
        for (int i = 1; i <= n; i++){
            int v = i, len = V2[u][i];
            if(len==V2[0][0]) continue;
            if(_h[v]==-1||_h[v] > ((long long)(_h[u])+len)){
                _h[v] = _h[u] + len;
                q.push((node){_h[v], v});
            }
        }
    }
}

bool a_star(int s, int k){
    while(q2.size()) q2.pop();
    memset(visit, 0, sizeof visit);
    
    nd root, u, no;
    root.h = _h[s];
    root.g = 0;
    root.f = root.g + root.h;
    root.num = s;
    q2.push(root);
    int cnt = 0;

    while(!q2.empty()){
        u = q2.top(); 
        q2.pop();
        visit[u.num]++;
        if(u.num == t){
            cnt++;
            if(visit[u.num] == k){
                printf("%d\n", u.g);
                return true;
            }
        }
        for (int i = 0; i < V[u.num].size(); i++){
            int v = V[u.num][i].first, len = V[u.num][i].second;
            no.h = _h[v];
            no.g = u.g + len;
            no.f = no.h + no.g;
            no.num = v;
            //visit[v]++;
            q2.push(no);

            //if(no.h == 0){
                //cnt++;
                //if(cnt == k){
                    //printf("%d\n", no.g);
                    //return true;
                //}
            //}
        }
    }
    return false;
}

int main()
{
    while(~scanf("%d%d", &n, &m)){
        for (int i = 0; i <= n; i++){
            V[i].clear();
        }
        memset(V2, inf, sizeof V2);
        for (int i = 0; i < m; i++){
            scanf("%d%d%d", &a, &b, &c);
            V[a].push_back(make_pair(b, c));
            if(c < V2[b][a])
                V2[b][a] = c;
        }
        scanf("%d%d%d", &s, &t, &k);
        calc_h(t);
        if(s == t) k++;
        if(!a_star(s, k)){
            printf("-1\n");
        }
    }
    return 0;
}
