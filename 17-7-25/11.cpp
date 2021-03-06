//#pragma comment(linker, "/STACK:1024000000,1024000000") 
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
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

//using namespace std;
using namespace fastIO;
struct Node{
	int l,r;
	int id;
}a[1000100];
int num[1000100],inv[1000100],now[1000100];
bool cmp(Node a,Node b){
	if(a.l==b.l) return a.r>b.r;
	return a.l<b.l;
}


char c[100];
int getnum(){
	int n;	
	n=0;
	if(fread(c,1,1,stdin)==0) return 0;
	while(c[0]<'0'||c[0]>'9'){
		if(fread(c,1,1,stdin)==0) return 0;
	}
	while(c[0]>='0'&&c[0]<='9'){
		n=n*10+c[0]-'0';
		if(fread(c,1,1,stdin)==0) return 0;
		fread(c,1,1,stdin);
	}
	return n;
}

long long ans;
long long mod=1000000007ll;
struct mynode{
	int l,r;
	mynode(){}
	mynode(int _l,int _r){
		l=_l,r=_r;
	}
};
std::queue<mynode> Q;

int getpow(int xx,int k){
	long long x=xx;
	long long ret=1;
	while(k){
		if(k&1) ret=ret*x%mod;
		k>>=1;
		x=x*x%mod;
	}
	int tp=ret;
	return tp;
}
int getinv(int x){
	if(inv[x]!=0) return inv[x];
	else return inv[x]=getpow(num[x],mod-2);
}
int flag;
void getans(int l,int r){
	//now[a[l].l]++;
	//cout << l << " " << r << endl;
	if(l==r) return;
	int l1=a[l].r-a[l].l;
	int r1=a[l+1].r-a[l+1].l+1;
//	while(l1==r1){
//		l++;
//		if(l==r) return;
//		l1--;
//		r1=a[l+1].r-a[l+1].l+1;
//	}
	//std::cout << l << " " << r << std::endl;
	//td::cout << l1 << " " << r1 << std::endl << std::endl;
	ans=ans*num[l1];
	if(ans>=mod) ans%=mod;
	ans*=getinv(l1-r1);
	if(ans>=mod)
	ans%=mod;
	ans*=getinv(r1);
	if(ans>=mod)
	ans%=mod;
	if(r1==l1){
		if(a[l].id>=a[l+1].l&&a[l].id<=a[l+1].r)
		{
			flag=0;
			return;
		}
		Q.push(mynode(l+1,r));
		//getans(l+1,r);
	}
	else{
		r1=a[l+1].r+2;
		l1=now[r1];
		if(r1!=a[l].id+1){
			flag=0;
			return;
		}
		if(a[l1].r!=a[l].r){
			flag=0;
			return;
		}
		Q.push(mynode(l+1,l1-1));
		Q.push(mynode(l1,r));
		//getans(l+1,l1-1);
		//getans(l1,r);
	}
}


void init(){
	int n=1000000;
	num[0]=1;
	for(int i=1;i<=n;i++)
		num[i]=(1ll*num[i-1]*i)%mod;
	inv[0]=inv[1]=1;
	for(int i=2;i<=n;i++)
		inv[i]=mod-(long long)mod/i*inv[mod%i]%mod;
	for(int i=2;i<=n;i++)
		inv[i]=(1ll*inv[i]*inv[i-1])%mod;
//	memset(inv,0,sizeof(inv));
//	for(int i=0;i<=n;i++)
//		inv[i]=getpow(num[i],mod-2);
}
//int l[1000100];
int main(){
	init();
	int n,cas=1;
	while(true){//~scanf("%d",&n)){
		//std::cout << "yes" << std::endl;
		read(n);
		if(fastIO::IOerror) break;
//		cout << n << endl;
		//if(n==0) break;
		////cout << n << endl;
		for(int i=0;i<n;i++){
		//	a[i].l=l[i];
	//		a[i].l=getnum();
			read(a[i].l);
//		cout<< a[i].l << endl;
		}
			//scanf("%d",&a[i].l);
//		fread(l,sizeof(int),n,stdin);
		for(int i=0;i<n;i++){
	//		a[i].r=getnum();
			read(a[i].r);
			a[i].id=i+1;
			//a[i].id=i;
		//	std::cout << a[i].r << std::endl;
			//scanf("%d",&a[i].r);
			//a[i].id=i;
			//v[i].clear();
			now[i]=-1;
		}
		now[n]=-1;
		std::sort(a,a+n,cmp);
		ans=1;
		
		
		for(int i=0;i<n;i++){
			if(now[a[i].l]==-1) now[a[i].l]=i;
		}
		/*
			//v[a[i].l].push_back(i);
			if(a[i].l==a[i].r) continue;
			int l=a[i].r-a[i].l;
			int r=i-a[i].l+1;
			if(r<0) continue;
//			cout << l << " " << r << endl;
//			cout << num[l]  << endl;
//			cout << inv[r] << endl;
//			cout << inv[l-r] << endl;
			ans=ans*num[l];
			if(ans>=mod) ans%=mod;
			ans*=inv[r];
			if(ans>=mod) ans%=mod;
			ans*=inv[l-r];
			if(ans>=mod) ans%=mod;
//			cout << ans << endl;
		}
		*/
		//ans=1;
		flag=1;
		while(!Q.empty()) Q.pop();
		Q.push(mynode(0,n-1));
 		while(!Q.empty()){
 			mynode tmp=Q.front();
 			Q.pop();
			//std::cout << tmp.l << " " << tmp.r << std::endl;
 			getans(tmp.l,tmp.r);
 		}
 		if(flag)
		printf("Case #%d: %lld\n",cas++,ans);
		else 
		printf("Case #%d: %lld\n",cas++,0ll);
	}
}
