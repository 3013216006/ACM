#include <iostream>
#include <cstdio>
#include <math.h>
#include <vector>
#include <algorithm>
#include <string.h>
#include <fstream>
#include <string.h>

#define lson l, m, rt<<1
#define rson m+1, r, rt<<1|1
#define mid (l+r)>>1
#define N 20100
using namespace std;

int col[N*4];
int le[10020],ri[10020];
int a[20050];
vector <int> b;

void Pushdown(int rt){
    col[rt<<1] = col[rt<<1|1] = col[rt];
    col[rt] = -1;
}


//线段树功能:update:区间染色 query:
void update(int L,int R,int c,int l,int r,int rt){
    if( L <= l && r<= R){
        col[rt] = c;
        return;
    }
    if(col[rt] != -1)Pushdown(rt);
    int m = (l+r) >> 1;
    if(L <= m)update(L,R,c,lson);
    if(R > m) update(L,R,c,rson);
}

int ans = 0;
bool has[20020];
void query(int l,int r,int rt) {
    if(col[rt] != -1){
        if(!has[col[rt]]){
            ans++;
            has[col[rt]] = true;
        }
        return;
    }
    if(l == r)return;
    int m = (l+r) >> 1;
    query(lson);
    query(rson);
}

int binary(int key,int n){
    int l = 0,r = n-1;
    while(l <= r){
        int m = (l+r) >> 1;
        if(b[m] == key)return m + 1;
        if(b[m] < key){
            l = m+1;
        }
        else r = m - 1;
    }
    return -1;
}


int main() {
    int T , n;
    scanf("%d",&T);
    for (int cas = 1 ; cas <= T ; cas ++) {
        int cnt = 0;
        scanf("%d",&n);
        for(int i = 0;i < n;i++){
            scanf("%d%d",le+i,ri+i);
            a[cnt++] = le[i];
            a[cnt++] = ri[i];
        }
        // 离散化
        sort(a,a+cnt);
        int last = a[0];
        b.push_back(a[0]);
        for(int i = 1;i < cnt;i++){
            if(a[i] != last){
                if(a[i] != last + 1){
                    b.push_back(last+1);
                    b.push_back(a[i]);
                }
                else{
                    b.push_back(a[i]);
                }
                last = a[i];
            }
        }
        int m = b.size();
        memset(col,-1,sizeof(col));
        cout << m  << endl;
        for(int i = 0;i < n;i++){
            int ll = binary(le[i],m);
  //          cout << ll <<" ";
            if(ll == -1){
                int fffff = 22;
                for(int i = 0; i < 200;i++){
                    cout << b[i] <<endl;
                }
                fffff = 44;

            }
            int rr = binary(ri[i],m);
    //        cout << rr << endl;
            update(ll,rr,i,1,m,1);
        }
        memset(has,false,sizeof(has));
        query(1,m,1);
        cout<<ans<<endl;
        ans = 0;
        b.clear();
    }
    return 0;
}
