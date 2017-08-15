#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int a[2000010];

int lowbit(int x){
	return x&(-x);
}

	int n,k;
void add(int x){
	while(x<=n+n){
		a[x]++;
		x+=lowbit(x);
	}
}

int  query(int x){
	int ret=0;
	while(x){
		ret+=a[x];
		x-=lowbit(x);
	}
	return ret;
}

int main(){
	while(~scanf("%d%d",&n,&k)){
		if(n<k*2) k=n-k;
		memset(a,0,sizeof(a));
		int st=1;
		long long ans=1;
		for(int i=0;i<n;i++){
			int sum=query(st+k)-query(st);
			int tp=st;
			st=st+k;
			if(st>n) st-=n,sum+=query(st-1);
			add(st);
			add(tp);
			sum++;
			ans+=sum;
			printf("%lld ",ans);
		}
		cout << endl;
	}
}
