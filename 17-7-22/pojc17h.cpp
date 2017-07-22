#include <iostream>
#include <map>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;
const long double PI = acos(-1.0);  
//复数结构体  
struct complex  
{  
    long double r,i;  
    complex(long double _r = 0.0,long double _i = 0.0)  
    {  
        r = _r; i = _i;  
    }  
    complex operator +(const complex &b)  
    {  
        return complex(r+b.r,i+b.i);  
    }  
    complex operator -(const complex &b)  
    {  
        return complex(r-b.r,i-b.i);  
    }  
    complex operator *(const complex &b)  
    {  
        return complex(r*b.r-i*b.i,r*b.i+i*b.r);  
    }  
};  
/* 
 * 进行FFT和IFFT前的反转变换。 
 * 位置i和 （i二进制反转后位置）互换 
 * len必须去2的幂 
 */  
void change(complex y[],int len)  
{  
    int i,j,k;  
    for(i = 1, j = len/2;i < len-1; i++)  
    {  
        if(i < j)swap(y[i],y[j]);  
        //交换互为小标反转的元素，i<j保证交换一次  
        //i做正常的+1，j左反转类型的+1,始终保持i和j是反转的  
        k = len/2;  
        while( j >= k)  
        {  
            j -= k;  
            k /= 2;  
        }  
        if(j < k) j += k;  
    }  
}  
/* 
 * 做FFT 
 * len必须为2^k形式， 
 * on==1时是DFT，on==-1时是IDFT 
 */  
void fft(complex y[],int len,int on)  
{  
    change(y,len);  
    for(int h = 2; h <= len; h <<= 1)  
    {  
        complex wn(cos(-on*2*PI/h),sin(-on*2*PI/h));  
        for(int j = 0;j < len;j+=h)  
        {  
            complex w(1,0);  
            for(int k = j;k < j+h/2;k++)  
            {  
                complex u = y[k];  
                complex t = w*y[k+h/2];  
                y[k] = u+t;  
                y[k+h/2] = u-t;  
                w = w*wn;  
            }  
        }  
    }  
    if(on == -1)  
        for(int i = 0;i < len;i++)  
            y[i].r /= len;  
}  
complex x1[9000],x2[9000];
int a[2010],a1[2010],b[2010];
int ans[2010][2011];
map<int, int> M;
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n,m,x,y;
		scanf("%d%d",&n,&m);
		int cnt = 0;
		M.clear();
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
			if(M.count(a[i]) > 0) continue;
			else M[a[i]] = cnt++;
		}
		memset(ans, 0, sizeof(ans));
		for(int i=0;i<n;i++){
			int tmp=0,tmp1=0;
			a1[tmp]=0;
			for(int j=i;j>=0;j--){
				if(a[j]>a[i]) tmp++,a1[tmp]=0;
				a1[tmp]++;
			}
			b[0]=0;
			for(int j=i;j<n;j++){
				if(a[j]>=a[i]) tmp1++,b[tmp1]=0;
				b[tmp1]++;
			}
//			cout << tmp1 << " " << tmp << endl;
			int l=tmp1+tmp+2;
			int r=1;
			while(r<=l) r*=2;
			for(int j=0;j<=tmp;j++){
				x1[j] = complex(a1[j]*1.0,0.0);
//				cout << j << ": " <<  a1[j] << endl;
			}
			for(int j=0;j<=tmp1;j++){
				x2[j] = complex(b[j]*1.0, 0.0);
//				cout << j << ": " << b[j] << endl;
			}
			for(int j = tmp + 1; j < r; j++)
				x1[j] = complex(0.0,0.0);
			for(int j = tmp1 + 1; j < r; j++){
				x2[j] = complex(0.0,0.0);
			}
			fft(x1,r,1);
			fft(x2,r,1);
			for(int j=0;j<r;j++){
				x1[j] = x1[j] * x2[j];
			}
			fft(x1,r,-1);
			tmp = M[a[i]];
			for(int j=0;j<min(r,n+1);j++){
				ans[tmp][j] += (int) (x1[j].r + 0.5);
//				cout << j << " " << ((int) (x1[i].r+0.5)) << endl;
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
