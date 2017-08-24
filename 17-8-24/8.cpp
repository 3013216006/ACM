#include <iostream>
#include <vector>
#include <stdio.h>
#include <string.h>
using namespace std;
int fl[100010],sum[100010];
int a[100010];
int v[100010];
char c;
int getnum(){
	int ret=0;
	while(c=getchar()){
		if(c>='0'&&c<='9') break;
	}
	ret=c-'0';
	while(c=getchar()){
		if(c>='0'&&c<='9') ret=ret*10+c-'0';
		else return ret;
	}
}
namespace fastIO {
    #define BUF_SIZE 100000
    //fread -> read
    bool IOerror = 0;
    inline char nc() {
        static char buf[BUF_SIZE], *p1 = buf + BUF_SIZE, *pend = buf + BUF_SIZE;
        if(p1 == pend) {
            p1 = buf;
            pend = buf + fread(buf, 1, BUF_SIZE, stdin);
            if(pend == p1) {
                IOerror = 1;
                return -1;
            }
        }
        return *p1++;
    }
    inline bool blank(char ch) {
        return ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t';
    }
    inline void read(int &x) {
        char ch;
        while(blank(ch = nc()));
        if(IOerror)
            return;
        for(x = ch - '0'; (ch = nc()) >= '0' && ch <= '9'; x = x * 10 + ch - '0');
    }
    #undef BUF_SIZE
};
using namespace fastIO;
int main(){
	int T,n,m,x,k;
	//scanf("%d",&T);
	T=getnum();
	while(T--){
		read(n);
		read(k);

		sum[1]=0;
		v[1]=0;
		for(int i=2;i<=n;i++){
			read(a[i]);
			sum[i]=0;
			v[i]=0;
		}
		int ans=0;
		int flag=0;
		int all=0;
		for(int i=n;i>=2;i--){
			if(sum[i]==0) sum[a[i]]++,ans++;
			else flag=max(flag,sum[i]),v[sum[i]]++,all++;
		}
		if(sum[1]==0) flag=2;
		else flag=max(flag,sum[1]),all++;
		v[sum[1]]++;
		ans=0;
		if(all*2>=k){
			ans=k/2;
			k=k&1;
			ans+=k;
		}
		else{
			ans=all;
			k-=all*2;
			ans+=k;
		}
		printf("%d\n",ans);
	}
}
