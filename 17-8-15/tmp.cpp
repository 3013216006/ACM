#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <complex>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;

typedef complex <double> Complex;
typedef vector <int> Polynomial;

const double PI = acos(-1.0);
const int N = 1 << 20;

void FFT(Complex* P, int n, int oper){
    for(int i = 1, j = 0; i < n-1; i++){
        for(int s = n; j^=s >>=1, ~j & s;);
        if (i < j){
            swap(P[i], P[j]);
        }
    }
    Complex unit_p0;
    for(int d = 0; (1 << d) < n; d++){
        int m = 1<<d, m2 = m * 2;
        double p0 = PI / m * oper;
        unit_p0 = Complex(cos(p0), sin(p0));
        for(int i = 0; i < n; i += m2)
        {
            Complex unit = 1;
            for(int j = 0; j < m; j++){
                Complex &P1 = P[i+j+m], &P2 = P[i+j];
                Complex t = unit * P1;
                P1 = P2 - t;
                P2 = P2 + t;
                unit = unit * unit_p0;
            }
        }
    }
}

Complex A[N], B[N];

Polynomial operator * (const Polynomial &u, const Polynomial &v)
{
    int n = 1, p = u.size(), q = v.size(), i;
    while(n <= p+q-2) n<<=1;
    for(i=0; i<n; ++i) A[i] = i<p?u[i]:0;
    for(i=0; i<n; ++i) B[i] = i<q?v[i]:0;
    FFT(A, n, 1);
    FFT(B, n, 1);
    for(i=0; i<n; ++i) A[i] *= B[i];
    FFT(A, n, -1);
    Polynomial w(q);
    for(i=0; i<q; ++i)
        w[i] = (int)(A[i].real()/n+0.5);
    for(i=0; i<q; ++i)
        w[i] = w[i] & 1;
    return w;
}
int fun(int x)
{
    int ans = 0;
    while(x % 2 == 0)
    {
        x /= 2;
        ans ++;
    }
    return ans;
}
int tt, i, n, m, x, j;
int q2[40];
int b[32][300000];
int ans[200010];
int a[200010], a1[200010];
int my[100],vis[100];
int main()
{
	time_t st=clock();
    scanf("%d", &tt);

    q2[1] = 1;
    for(i=2; i<=30; i++)
        q2[i] = q2[i-1]*2;
    while(tt--)
    {
        memset(b, 0, sizeof(b));
        scanf("%d%d", &n, &m);
		int mx=0;
        for(i=0; i<n; i++)
        {
            scanf("%d", &x);
			mx=max(mx,x);
            a[i] = x;
            int l = 0;
            while(x)
            {
                b[++l][i] = x%2;
                x = x / 2;
            }
        }

        Polynomial F(n);
        Polynomial F1(n);
        F[0] = 0;
        for(i=1; i<n; i++)
        {
            F[i] = F[i-1] + fun(m+i-1) - fun(i);
        }
        for(i=0; i<n; i++)
            F[i] = (F[i] == 0?1:0);

        memset(ans, 0, sizeof(ans));
		memset(vis,0,sizeof(vis));
        for(i=1; i<=30; i++)
        {
			if(vis[i])continue;
			if(1<<(i-1)>mx) break;
           // cout<<'x'<<i<<endl;
		   int tp=0;
		   my[tp++]=i;
		   for(int j=i+1;j<=30;j++){
			if(vis[j]) continue;
			if(1<<(j-1)>mx) break;
			int fl=1;
			for(int k=0;k<n&&fl;k++){
				fl=(b[i][k]==b[j][k]);
			}
			if(fl) vis[j]=1,my[tp++]=j;
		   }
            for(j=0; j<n; j++)
                F1[j] = b[i][j];
           /* for(j=0; j<n; j++)
                cout<<F1[j]<<' ';
            cout<<endl; */
            F1 = F1 * F;
            for(j=0; j<n; j++)
                if (F1[j] == 1) for(int k=0;k<tp;k++) ans[j] = ans[j] + q2[my[tp]];
          /*  for(j=0; j<n; j++)
                cout<<ans[j]<<' ';
            cout<<endl; */
        }
        for(i=0; i<n-1; i++)
            printf("%d ", ans[i]);
        printf("%d\n", ans[n-1]);

        /*
        for(i=1; i<=m; i++)
        {
            a1[0] = a[0];
            for(j=1; j<n; j++)
                a1[j] = a1[j-1] ^ a[j];
            for(j=0; j<n; j++)
                a[j] = a1[j];
        }
        for(i=0; i<n; i++)
            cout<<a[i]<<' ';
        cout<<endl; */
    }
	time_t ed=clock();
	printf("%.3f\n",1.0*(ed-st)/CLOCKS_PER_SEC);
}
