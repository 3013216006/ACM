#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int vis[100010],p[100010],pl;
void init(){
	pl=0;
	memset(vis,0,sizeof(vis));
	for(int i=2;i<=100000;i++){
		if(vis[i]) continue;
		p[pl++]=i;
		for(int j=i+i;j<=100000;j+=i)
			vis[j]=1;
	}
}

bool _is(long long x){
	int l=0,r=1000000;
	long long tp=0;
	while(l<=r){
		int mid=l+r>>1;
		tp=1ll*mid*mid*mid;
		if(tp<x) l=mid+1;
		else if(tp>x) r=mid-1;
		else return 1;
	}
	return 0;
}

int main(){
	init();
	int T;
	int n,m;
	int t1,t2;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		int d=__gcd(n,m);
		long long tmp=1ll*n*m;
		if(_is(tmp)==0){
			puts("No");
			continue;
		}
		if(d%(n/d)==0&&d%(m/d)==0) puts("Yes");
		else puts("No");
		continue;
		int flag=1;
		for(int i=0;i<pl&&flag;i++){
			t1=0,t2=0;
			if(n==1) break;
			if(m==1) break;
			while(n%p[i]==0) n/=p[i],t1++;
			while(m%p[i]==0) m/=p[i],t2++;
			if((t1+t2)%3) flag=0;
			if(t1*2<t2||t2*2<t1) flag=0;
		}
		if(n!=1||m!=1) flag=0;
		if(flag) puts("Yes");
		else puts("No");
	}
}
