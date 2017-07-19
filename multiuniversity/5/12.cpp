#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
int n,m;
int a[50020],b[50020],t[50020];
void init_hash(){
	for(int i=0;i<=n;i++)
		t[i+1]=a[i];
	sort(t+1,t+n+1);
	m=unique(t+1,t+n+1)-t+1;
}

int hash(int x){
	return lower_bound(t+1,t+1+m,x)-t;
}

int lowbit(int x){
	return x&-x;
}

void add(int x){
	while(x<=n){
		b[x]++;
		x+=lowbit(x);
	}
}

int query(int x){
	int ret=0;
	while(x){
		ret+=b[x];
		x-=lowbit(x);
	}
	return ret;
}

int main(){
	int n;
	while(~scanf("%d",&n)){
		for(int i=0;i<n;i++)
			scanf("%d",&a[i]);
		memset(b,0,sizeof(b));
		init_hash();
		long long x=0,y=0;
		for(int i=0;i<n;i++){
			int c=hash(a[i]);
			int tmp=query(c);
			add(c);
			x+=tmp;
			y+=i-tmp;
		}
		x=x*y;
		cout << x << endl;
	}
}
