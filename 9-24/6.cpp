#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <math.h>
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
const int MAXN = 100010*4;
complex x1[MAXN],x2[MAXN];
int main()
{
    int T,n;
    int x;
    long long y;
    scanf("%d",&T);
    while(T--){
    	scanf("%d",&n);
    	long long ans=0;
    	int my1=1024,my2=1024;
    	for(int i=0;i<n;i++){
    		scanf("%d",&x);
    		y=x;
    		ans+=y*y;
    		x1[i]=complex(x,0);
    	}
    	for(int i=0;i<n;i++){
    		scanf("%d",&x);
                y=x;
    		ans+=y*y;
    		x2[n-i-1]=complex(x,0);
    	}
    	for(int i=0;i<n;i++) x1[i].r/=my1,x2[i].r/=my2;
    	int l=1;
	while(l<n+n-1) l*=2;
    	for(int i=n;i<l;i++) x1[i]=complex(0,0),x2[i]=complex(0,0);
    	fft(x1,l,1);
	fft(x2,l,1);
	for(int i=0;i<l;i++) x1[i]=x1[i]*x2[i];
	fft(x1,l,-1);
	long long jian=(long long)(x1[n-1].r*my1*my2+0.5); 
	for(int i=0;i<n-1;i++){
		long long tmp=(long long)(x1[i].r*my1*my2+0.5)+(long long)(x1[i+n].r*my2*my1+0.5);
		jian=max(tmp,jian);
	}
	ans=ans-jian*2;
	cout << ans << endl;
    }
    return 0;
}

