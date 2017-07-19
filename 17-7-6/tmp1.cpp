#include<iostream>  
#include<sstream>  
#include<fstream>  
#include<vector>  
#include<list>  
#include<deque>  
#include<queue>  
#include<stack>  
#include<map>  
#include<set>  
#include<bitset>  
#include<algorithm>  
#include<cstdio>  
#include<cstdlib>  
#include<cstring>  
#include<cctype>  
#include<cmath>  
#include<ctime>  
#include<iomanip>  
#define INF 2147483647  
#define cls(x) memset(x,0,sizeof(x))  
#define rise(i,a,b) for(int i = a ; i <= b ; i++)  
using namespace std;  
const double eps(1e-8);  
typedef long long lint;  
  
const int maxn = 365;  
const int maxd = 365;  
const lint mod = 1e9 + 7;  
lint dp[maxn][maxd];  
lint C[maxn][maxd];  
void init(){  
    cls(C);  
    memset(dp,-1,sizeof(dp));  
    C[0][0] = 1;  
    for(int i = 1 ; i < maxn  ; i++){  
        C[i][0] = 1;  
        for(int j = 1 ; j <= i ; j++){  
            C[i][j] = C[i-1][j-1] + C[i-1][j];  
//          printf("C[%d][%d] : %I64d\n" ,i ,j ,C[i][j]);  
            if(C[i][j] > mod) C[i][j] -= mod;  
        }  
    }  
}  
  
lint f(int n , int d){  
    if(n == 1 && d >= 1) return 1;  
    if(n == 1 || d == 0) return 0;  
    if(dp[n][d] != -1) return dp[n][d];  
    lint &ans = dp[n][d];  
    ans = (f(n-1 , d-1) * C[n][1] * 2) % mod;  
    for(int k = 1 ; k <= n-2 ; k++)  
        ans = (ans + ((( ( (f(n-k-1 , d-1) * f(k , d-1)) % mod) * C[n-2][k]) % mod) * C[n][1]) % mod) % mod;  
    return ans;  
}  
  
int main(){  
    int t ; cin >> t ; int kase = 1;  
    init();  
    while(t--){  
        int n , d;  
        cin >> n >> d;  
        lint ans = f(n,d) - f(n,d-1);  
        ans = (ans + mod) % mod;  
        cout << "Case #" << kase++ << ": " << ans << endl;  
    }  
    return 0;  
}  
