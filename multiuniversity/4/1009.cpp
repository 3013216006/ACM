#include <cstring>
#include <algorithm>
using namespace std;

const long long  maxn = 1100;

long long  t,n,x[maxn],a[maxn],b[maxn],w[maxn][maxn],cnt[maxn];

bool v[maxn];

char buf[maxn];

long long  cas = 1;

int  main(){
    scanf("%lld",&t);
    while(t--){
        scanf("%lld",&n);
       // scanf("%s",buf);
       getchar();
       gets(buf);
        memset(v,0,sizeof v);
        memset(cnt,0,sizeof cnt);
        for(long long  i=0;i<n;i++){
            x[i] = buf[i] - '0';
            cnt[x[i]]++;
            v[i] = true;
        }
        for(long long  i=0;i<10;i++){
            scanf("%d%d",a+i,b+i);
        }
        for(long long  i=0;i<n;i++){
            for(long long  j=0;j<n;j++){
                scanf("%d",&w[i][j]);
            }
        }
        long long  ans = 0;
        for(long long  i=0;i<n;i++){
            for(long long  j=i+1;j<n;j++){
                w[i][j] =  w[j][i] = w[i][j] + w[j][i];
                ans += w[i][j];
            }
        }
        for(long long  i=0;i<10;i++){
            if(cnt[i]>0){
                ans -= (cnt[i]-1)*a[i] + b[i];
            }
        }
        //prlong long f("%d\n",ans);
        while(1){
            bool ok = true;
            long long  dt = 0 ,mxdt = 0;
            long long  k = 0;
            for(long long  i=0;i<n;i++){
                dt = 0;
                if(v[i]){
                    if(cnt[x[i]]>1){
                        dt += a[x[i]];
                    }else{
                        dt += b[x[i]];
                    }
                    for(long long  j=0;j<n;j++){
                        if(v[j]){
                            dt -= w[i][j];
                        }
                    }
                    if(dt>mxdt){
                        mxdt = dt;
                        k = i;
                    }
                }
            }
            if(mxdt==0) break;
            ans += mxdt;
            v[k] = 0;
            cnt[x[k]]--;
        }
        printf("Case #%lld: %lld\n",cas++,ans);
    }
    return 0;
}
