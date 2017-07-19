#include<cstdio>
#include<string.h>

const int maxn = 200005;

int ans[maxn], col[maxn], a[maxn], ans1[maxn], ans2[maxn];
int x[maxn], y[maxn];

struct node
{
    int val, l, r;
}tree[maxn * 10];

void build(int l, int r, int pos)
{
    col[pos] = 0;
    tree[pos].l = l;
    tree[pos].r = r;
    if(l == r)
        return;
    int m = (l + r) >> 1;
    build(l, m, pos * 2);
    build(m + 1, r, pos * 2 + 1);
}

void push_down(int rt)
{
    if(col[rt])
    {
        col[rt << 1] = col[rt];
        col[rt << 1 | 1] = col[rt];
        col[rt] = 0;
    }
}

void update(int l, int r, int v, int ll, int rr, int rt)
{
    if(l <= ll && r >= rr)
    {
        col[rt] = v;
        return ;
    }
    push_down(rt);
    int mid = (ll + rr) >> 1;
    if(l <= mid)
        update(l, r, v, ll, mid, rt << 1);
    if(r > mid)
        update(l, r, v, mid + 1, rr, rt << 1 | 1);
}

void dfs(int rt)
{
    int l = tree[rt].l;
    int r = tree[rt].r;
    if(l == r)
    {
        if(col[rt])
            ans1[col[rt]] += a[l];
        return ;
    }
    if(col[rt])
    {
        for(int i = l; i <= r; i ++)
        {
            ans1[col[rt]] += a[i];
        }
        return ;
    }
    dfs(rt << 1);
    dfs(rt << 1 | 1);
}

void dfs1(int rt)
{
    int l = tree[rt].l;
    int r = tree[rt].r;
    if(l == r)
    {
        if(col[rt])
        ans2[col[rt]] -= a[l];
        return ;
    }
    if(col[rt])
    {
        for(int i = l; i <= r; i ++)
        {
            ans2[col[rt]] -= a[i];
        }
        return ;
    }
    dfs1(rt << 1);
    dfs1(rt << 1 | 1);
}

int main ()
{
    int n, m;
    while(~scanf("%d %d", &n, &m))
    {
        for(int i = 1; i < n; i ++)
            scanf("%d", &a[i]);
        for(int i = 0; i <= n; i ++)
        {
            ans[i] = 0;
            ans1[i] = 0;
            ans2[i] = 0;
        }


        build(1, n, 1);
        for(int i = 1; i <= m; i ++)
        {
            scanf("%d %d", &x[i], &y[i]);
            y[i] --;
            update(x[i], y[i], i, 1, n, 1);
        }
        dfs1(1);
//        for(int i = 1; i <= m; i ++)
//        {
//            printf("%d %d ", ans1[i], ans2[i]);
//        }
//        printf("\n");

        build(1, n, 1);
        for(int i = m; i > 0; i --)
        {
            update(x[i], y[i], i, 1, n, 1);
        }
        dfs(1);
//        for(int i = 1; i <= m; i ++)
//        {
//            printf("%d %d ", ans1[i], ans2[i]);
//        }
//        printf("\n");

        for(int i = 1; i<= m; i ++)
        {
            ans[i] = ans[i - 1] + ans1[i] + ans2[i - 1];
            printf("%d\n", ans[i]);
        }
    }
    return 0;
}
