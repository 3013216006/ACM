#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <iostream>
using namespace std;
const int maxn = 2e5+10;
int n,q,tot;
int a[maxn],T[maxn],lson[maxn<<5],rson[maxn<<5],c[maxn<<5];

int build(int l,int r){
    int root = tot++;
    c[root] = 0;
    if(l!=r){
        int mid = (l+r) >> 1;
        lson[root] = build(l,mid);
        rson[root] = build(mid+1,r);
    }
    return root;
}

int update(int root,int pos,int val){
    int newroot = tot++,tmp = newroot;
    c[newroot] = c[root] + val;
    int l = 1,r = n;
    while(l<r){
        int mid = (l+r) >> 1;
        if(pos<=mid){
            lson[newroot] = tot++;rson[newroot] = rson[root];
            newroot = lson[newroot];root = lson[root];
            r = mid;
        }else{
            rson[newroot] = tot++;lson[newroot] = lson[root];
            newroot = rson[newroot];root = rson[root];
            l = mid+1;
        }
        c[newroot] = c[root] + val;
    }
    return tmp;
}

int query(int root,int pos){
    int ret = 0;
    int l = 1, r = n;
    while(pos<r){
        int mid = (l+r) >> 1;
        if(pos <= mid){
            r = mid;
            root = lson[root];
        
        }else{
            ret += c[lson[root]];
            root = rson[root];
            l = mid+1;
        }
    }
    return ret+c[root];
}

        map<int,int> mp;
int query1(int root,int pos,int k){
    int ret = 0;
    int l = 1, r = n,ans=l;
    while(l<r){
        int mid = (l+r) >> 1;
            ret += c[lson[root]];
            if(ret>=k){
           	ret-=c[lson[root]];
           	root=lson[root];
		r=mid;
            }
            else{
		root = rson[root];
		l = mid+1;
	    }
    }
    return l;
}

int tt,l,r,ans[maxn],cas = 1;

int nxtl(int i,int l,int r){
    //printf("args = %d %d %d\n",a[i-1],l,r);
    return min((l+ans[i-1])%n,(r+ans[i-1])%n)+1;
}

int nxtr(int i,int l,int r){
    return max((l+ans[i-1])%n,(r+ans[i-1])%n)+1;
}

int solve(){
    //printf("q = %d %d\n",l,r);
    int k = query(T[l],r);
    int h = (k/2)+(k&1);
    int tmp=query1(T[l],r,h);
    return tmp;
}

int main(){
    scanf("%d",&tt);
    while(tt--){
        ans[0] = 0;
        scanf("%d%d",&n,&q);
        tot = 0;
        for(int i=1;i<=n;i++) scanf("%d",a+i);
        mp.clear();
        T[n+1] = build(1,n);
        for(int i=n;i>=1;i--){
            if(mp.find(a[i])==mp.end()){
                T[i] = update(T[i+1],i,1);
            }else{
                int tmp = update(T[i+1],mp[a[i]],-1);
                T[i] = update(tmp,i,1);
            }
            mp[a[i]] = i;
        }
        printf("Case #%d:",cas++);
        for(int qy=1;qy<=q;qy++){
            scanf("%d%d",&l,&r);
            int tl = l,tr = r;
            l = nxtl(qy,tl,tr);
            r = nxtr(qy,tl,tr);
            printf(" %d",ans[qy] = solve());
        }
        puts("");
    }
    return 0;
}
