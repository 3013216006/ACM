#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#define MAXN 500000
using namespace std;
struct Node{
	int v,next;
}edge[MAXN];

struct node{
	int lmost, rmost, sum;
	void init(){
		lmost = -1;
		rmost = -1;
		sum = 0;
	}
};

int lmost[MAXN],rmost[MAXN],sum[MAXN],size[MAXN],f[MAXN],
	son[MAXN],a[MAXN],b[MAXN],dep[MAXN],topfa[MAXN],opn[MAXN],
	op[MAXN];
int head[MAXN],v[MAXN];
int cnt;
int n, m;
char s[100];

void add(int x, int y){
	edge[cnt].next = head[x];
	edge[cnt].v = y;
	head[x] = cnt++;
	
	edge[cnt].next = head[y];
	edge[cnt].v = x;
	head[y] = cnt++;
}

void dfs1(int x, int fa, int deep){
	f[x] = fa;
	dep[x] = deep;
	size[x] = 1;
	son[x] = -1;
	for(int i = head[x]; i != -1; i = edge[i].next){
		int v = edge[i].v;
		if(v==fa) continue;
		dfs1(v, x, deep+1);
		size[x] += size[v];
		if(son[x] == -1 || size[v] > size[son[x]]){
			son[x] = v;
		}
	}
}

int nu;
void dfs2(int x, int fa, int tf){
	topfa[x] = tf;
	a[x] = nu++;
	if(son[x] != -1)
		dfs2(son[x], x, tf);
	for(int i = head[x]; i != -1; i = edge[i].next){
		int v = edge[i].v;
		if(v == fa || v == son[x]) continue;
		dfs2(v, x, v);
	}
}

void update(int rt, int ls ,int rs){
	sum[rt] = sum[ls] + sum[rs];
	lmost[rt] = lmost[ls];
	rmost[rt] = rmost[rs];
	if(rmost[ls] == lmost[rs]){
		sum[rt]--;
	}
	return ;
}

node update(node l,node r){
	node ret;
	if(l.sum == 0) return r;
	if(r.sum == 0) return l;
	ret.lmost = l.lmost;
	ret.rmost = r.rmost;
	ret.sum = l.sum + r.sum;
	if(l.rmost == r.lmost)
		ret.sum--;
	return ret;
}

void build(int l, int r, int rt){
	if(l == r){
		sum[rt] = 1;
		lmost[rt] = v[b[l]];
		rmost[rt] = v[b[l]];
		//cout << "l = " << l << "v = " << v[b[l]]  << endl;
		return;
	}
	int mid = l + r >> 1, ls = rt << 1, rs = ls | 1;
	build(l, mid, ls);
	build(mid + 1, r, rs);
	update(rt, ls, rs);
}

void pushdown(int rt, int ls, int rs){
	op[rt] = 0;
	sum[ls] = sum[rs] = op[ls] = op[rs] = 1;
	lmost[ls] = rmost[ls] = lmost[rs] = rmost[rs] = opn[ls] = opn[rs] = opn[rt];
}

void change(int l, int r, int rt, int L, int R, int x){
	if(l <= L && R <= r){
		lmost[rt] = x;
		rmost[rt] = x;
		sum[rt] = 1;
		op[rt] = 1;
		opn[rt] = x;
		return;
	}
	int mid = L + R >> 1, ls = rt << 1, rs = ls | 1;
	if(op[rt]) pushdown(rt, ls, rs);
	if(r <= mid){
		change(l, r, ls, L, mid, x);
	}
	else
		if(l > mid) 
			change(l, r, rs, mid + 1, R, x);
		else{
			change(l, mid, ls, L, mid, x);
			change(mid + 1, r, rs, mid + 1, R, x);
		}
		
	update(rt, ls ,rs);
}

node query(int l, int r, int rt, int L, int R){
	node ret;
	if((l == L && r == R) || op[rt]){
		ret.lmost = lmost[rt];
		ret.rmost = rmost[rt];
		ret.sum = sum[rt];
	//cout << "query:\n";
	//cout << l << " " << r << " " << L << " " <<  R << endl;
	//cout << ret.lmost << " " << ret.rmost << " " << ret.sum << endl;
		return ret;
	}
	int mid = L + R >> 1, ls = rt << 1, rs = ls |1;
	node retl,retr;
	retl.init();
	retr.init();
	if(r <= mid) retl = query(l, r, ls, L, mid);
	else
	if(l > mid) retr = query(l, r, rs, mid + 1, R);
	else{
		retl = query(l, mid, ls, L ,mid);
		retr = query(mid+1, r, rs, mid + 1, R);
	}
	ret = update(retl, retr);
	//cout << "query:\n";
	//cout << l << " " << r << " " << L << " " <<  R << endl;
	//cout << ret.lmost << " " << ret.rmost << " " << ret.sum << endl;
	return ret;
}

node getans(int x, int y){
	node ret;
	if(dep[topfa[x]] < dep[topfa[y]]){
		node tmp = getans(x, f[topfa[y]]);
		ret = query(a[topfa[y]], a[y], 1, 1, n);
		ret = update(tmp, ret);
		//cout << "getans1" << endl;
		//cout << x << " " << y << endl;
		//cout << "topfa[y]=" << topfa[y] << endl;
		//cout << ret.lmost << " " << ret.rmost << " " << ret.sum << endl;
		return ret;
	}
	if(topfa[x] == topfa[y]){
		if(dep[x] < dep[y]){
			ret= query(a[x], a[y], 1, 1, n);
		}
		else{
			ret = query(a[y], a[x], 1, 1, n);
			swap(ret.lmost, ret.rmost);
		}
		//cout << "getans2" << endl;
		//cout << x << " " << y << endl;
		//cout << ret.lmost << " " << ret.rmost << " " << ret.sum << endl;
		return ret;
	}
	node tmp = query(a[topfa[x]], a[x], 1, 1, n);
	swap(tmp.lmost, tmp.rmost);
	ret = getans(f[topfa[x]], y);
	ret = update(tmp, ret);
	//cout << "getans3" << endl;
		//cout << x << " " << y << endl;
		//cout << ret.lmost << " " << ret.rmost << " " << ret.sum << endl;
	return ret;
}

void mychange(int x, int y, int V){
	if(dep[topfa[x]] < dep[topfa[y]]){
		swap(x,y);
	}
	if(topfa[x] == topfa[y]){
		if(dep[x] < dep[y])
			change(a[x], a[y], 1, 1, n, V);
		else
			change(a[y], a[x], 1, 1, n, V);
		return;
	}
	change(a[topfa[x]], a[x], 1, 1, n, V);
	mychange(f[topfa[x]], y, V);
	return;
}

int main(){
	int x, y, z;
	while(~scanf("%d%d", &n, &m)){
		memset(head, -1, sizeof(head));
		cnt = 0;
		for(int i = 1; i <= n; i++){
			scanf("%d", &v[i]);
		}
		for(int i = 1; i < n; i++)
		{
			scanf("%d%d", &x, &y);
			add(x, y);
		}
		nu = 1;
		dfs1(1, 0, 0);
		dfs2(1, 0, 1);
		for(int i = 1; i <= n; i++){
			b[a[i]] = i;
			//cout << a[i] << " " << i << endl;
		}
		build(1, n, 1);
		for(int i = 0; i < m; i++){
			scanf("%s %d%d", s, &x, &y);
			if(s[0] == 'Q'){
				node ans = getans(x, y);
				printf("%d\n", ans.sum);
			}
			else{
				scanf("%d", &z);
				mychange(x, y, z);
			}
		}
	}
}
