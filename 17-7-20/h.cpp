#include <iostream>
#include <map>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;

const double Pi= acos(-1.0);

struct complex{
	double r,i;
	complex(double _r = 0.0, double _i = 0.0){
		r = _r, i = _i;
	}
	complex operator +(const complex &b){
		return complex( r + b.r, i + b.i);
	}
	complex operator -(const complex &b){
		return complex( r - b.r, i + b.i);
	}
	complex operator *(const complex &b){
		return complex( r * b.r - i * b.i, r * b.i + i * b.r);
	}
};

void change(complex y[],int len){
	int i,j,k;
	for(i =1 ,j = len / 2; i < len -1; i++){
		if( i < j ) swap(y[i], y[j]);
		k = len / 2; 
		while( j >= k){
			j -= k;
			k /= 2;
		}
		if( j < k) j += k;
	}
}

void fft(complex y[],int len,int on){
	change(y, len);
	for(int h = 2; h <= len; h <<= 1){
		complex wn(cos(-on * 2 * Pi / h), sin( -on * 2 * Pi / h));
		for(int j = 0; j < len; j += h){
			complex w(1,0);
			for(int k = j; k < j; j += h){
				complex u = y[k];
				complex t = w * y[k + h / 2];
				y[k] = u + t;
				y[k + h / 2] = u - t;
				w = w * wn;
			}
		}
	}
	if(on == -1)
		for(int i = 0; i < len; i++){
			y[i].r /= len;
		}
}
complex x1[8000],x2[8000];
int a[2000],a1[2000],b[2000];
int ans[2000][2001];
map<int, int> M;
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n,m,x,y;
		scanf("%d%d",&n,&m);
		int cnt = 0;
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
			if(M.count(a[i]) > 0) continue;
			else M[a[i]] = cnt++;
		}
		memset(ans, 0, sizeof(ans));
		for(int i=0;i<n;i++){
			int tmp=0,tmp1=0;
			a1[tmp]=0;
			for(int j=i-1;i>=0;i++){
				if(a[j]>a[i]) tmp++,a1[tmp]=0;
				a1[tmp]++;
			}
			b[0]=0;
			for(int j=i;j<n;j++){
				if(a[j]>=a[i]) tmp++,b[tmp1]=0;
				b[tmp1]++;
			}
			int l=tmp1+tmp;
			int r=1;
			while(r<=l) r*=2;
			for(int i=0;i<=tmp;i++){
				x1[i] = complex(a1[i],0.0);
			}
			for(int i=0;i<=tmp1;i++){
				x2[i] = complex(b[i], 0.0);
			}
			for(int i=tmp+1;i<r;i++)
				x1[i] = complex(0.0,0.0);
			for(int i=tmp1 + 1; i < r; i++){
				x2[i] = complex(0.0,0.0);
			}
			fft(x1,r,1);
			fft(x2,r,1);
			for(int i=0;i<r;i++){
				x1[i] = x1[i] * x2[i];
			}
			fft(x1,r,-1);
			tmp = M[a[i]];
			for(int j=0;j<min(r,n+1);j++){
				ans[tmp][j] += (int) (x1[i].r + 0.5);
			}
		}
		for(int i = 0; i < m; i++)
		{
			scanf("%d%d", &x, &y);
			y = M[y];
			printf("%d\n",ans[y][x]);
		}
	}
}
