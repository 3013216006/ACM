#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll maxn = 50 + 5;
const ll maxm = 1e4 + 10;
ll a[maxn],b[maxm];
ll num[maxm],cnt[maxm];
ll n,m;
int main()
{
    ll kase;scanf("%lld",&kase);
    while(kase--){
        memset(cnt,0,sizeof(cnt));
        memset(num,0,sizeof(num));
        scanf("%lld%lld",&n,&m);
        for(ll i = 0;i <= m;i++) scanf("%lld",&b[i]);
        while((1LL << num[0]) < b[0]) num[0]++;
        ll pow20 = (1LL << num[0]);
        cnt[0] = b[0];
        int maxnow = 0;
//        prllf("poo:  %d\n",pow20);
        for(int i = 1;i <= m;i++){
            if(b[i] <= cnt[i]) continue;
            ll tmp = b[i] - cnt[i];
            num[i] = tmp / pow20;//????
//            prllf("num[i]:  %d\n",num[i]);
            for(int j = 1;j <= num[i];j++){
                maxnow = maxnow + i;
                for(int k = maxnow;k >= i;k--)
                if(cnt[k-i]){
                    cnt[k] += cnt[k - i];
                }
            }
            //cnt[i] = b[i];
        }
//        for(ll i = 0;i <= m;i++) prllf("%d\n",num[i]);
        ll flag = 0;
        for(ll i = 0;i <= m;i++){
            for(ll j = 1;j <= num[i];j++){
                if(flag) printf(" ");flag = 1;
                printf("%lld",i);
            }
        }
        printf("\n");
    }
    return 0;
}
