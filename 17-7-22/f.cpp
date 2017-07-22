nclude <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int nn = 1000000007;
struct st1
{
	    int y, ne;
}a[1000000];
struct st2
{
	    int l, r, z, z1, z2, z3, mid;
}tree[2500000];
int tt, n, l, i, j, k, pp, x, q, ll, m, v;
int deep[1000000], pos1[1000000], pos2[1000000], pos[1000000], h[500000];

int fmin(int x, int y){return x<y?x:y;}
void dfs(int x)
{
	    ll++;
		    pos1[x] = ll;
			    pos[ll] = x;
				    int p = h[x];
					    while(p)
							    {
									        deep[a[p].y] = deep[x]+1;
											        dfs(a[p].y);
													        p = a[p].ne;
															    }
																    pos2[x] = ll;
																	    return;
}
void maketree(int x, int l, int r)
{
	    tree[x].l = l; tree[x].r = r; tree[x].mid = (l+r)/2;
		    if (l == r)
				    {
						        tree[x].z = 0;
								        tree[x].z1 = deep[pos[l]];
										        tree[x].z2 = 0;
												        tree[x].z3 = 0; return;
														    }
															    maketree(x*2, l, tree[x].mid);
																    maketree(x*2+1, tree[x].mid+1, r);
																	    tree[x].z1 = fmin(tree[x*2].z1, tree[x*2+1].z1);
																		    tree[x].z2 = 0; tree[x].z3 = 0; tree[x].z = 0;
																			    return;
}

void down(int x)
{
    if (tree[x].z2 == 0 && tree[x].z3 == 0) return;
	    if (tree[x].l == tree[x].r) {
			 return;
 		}

    int l = x*2;
    int r = x*2+1;
    long long xx = (long long)tree[x].z3 *(tree[l].z1 - tree[x].z1);
    xx = xx % nn;
    tree[l].z2 = ((tree[x].z2-xx)%nn+tree[l].z2)%nn;
    if (tree[l].z2 < 0) tree[l].z2 += nn;
    tree[l].z3 = (tree[l].z3+tree[x].z3)%nn;

    xx = (long long)tree[x].z3 *(tree[r].z1 - tree[x].z1);
    xx = xx % nn;
    tree[r].z2 = ((tree[x].z2-xx)%nn+tree[r].z2)%nn;
    if (tree[r].z2 < 0) tree[r].z2 += nn;
    tree[r].z3 = (tree[r].z3+tree[x].z3)%nn;
	tree[x].z2 = 0; tree[x].z3 = 0; return;
}
void change(int x, int l, int r, int x1, int k,int d)
{
	    down(x);
	    if (tree[x].l == l && tree[x].r == r)
	    {
			long long xx=(long long)k*(tree[x].z1-d);
			xx%=nn;
			x1-=xx;
			x1%=nn;
			if(x1<0) x1+=nn;
	        tree[x].z2 = (tree[x].z2+x1)%nn;
	        if (l != r)
	        {
	            tree[x].z3 = (tree[x].z3+k)%nn;
	        }
	        return;
	    }
	    if (r <= tree[x].mid) {change(x*2, l, r, x1, k,d); return;}
	    if (l > tree[x].mid) {change(x*2+1, l, r, x1, k,d); return;}
	    change(x*2, l, tree[x].mid, x1, k,d);
	    change(x*2+1, tree[x].mid+1, r, x1, k,d);
	    return;
}
int query(int x, int k)
{
	    down(x);
		    if (tree[x].l == tree[x].r)
				    {
						        return tree[x].z2;
								    }
									    if (k <= tree[x].mid) return query(x*2, k); else return query(x*2+1, k);
}

void makeedge(int x, int y)
{
	    pp++;
		    a[pp].y = y; a[pp].ne = h[x]; h[x] = pp;
}
int main()
{
	scanf("%d", &tt);
	while(tt--){
	        scanf("%d", &n);
	        memset(h, 0, sizeof(h)); pp = 0;
	        for(i=2; i<=n; i++)
	        {
	            scanf("%d", &x);
	            makeedge(x, i);
	       }
		   ll = 0;
																										        deep[1] = 1;
																												        dfs(1);

																														        maketree(1, 1, ll);
																																        scanf("%d", &m);
																																		        for(i=1; i<=m; i++)
																																					        {
																																								            scanf("%d", &q);
																																											            if (q == 1)
																																															            {
																																																			                scanf("%d%d%d", &v, &x, &k);
																																																							                change(1, pos1[v], pos2[v], x, k,deep[v]);
																																																											            }
																																																														            if (q == 2)
																																																																		            {
																																																																						                scanf("%d", &v);
																																																																										                printf("%d\n", query(1, pos1[v]) % nn);
																																																																														            }
																																																																																	        }
																																																																																			    }
} /*
1
9
4 7 1 7 1 1 4 8
10
1 1 10 1
2 9
1 4 9 5
2 9
*
