#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
int a[100100],ansl[200000],ansr[100100];
int lowbit(int x){
	return x&(-x);
}
int n,cas=1;
void add(int x){
	while(x<=n){
		a[x]++;
		x+=lowbit(x);
	}
}

int query(int x){
	int ret=0;
	while(x){
		ret+=a[x];
		x-=lowbit(x);
	}
	return ret;
}


int main(){
	int T,x;
	scanf("%d",&T);
	while(T--){
		memset(a,0,sizeof(a));
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&x);
			add(x);
			int y=query(x);
			ansl[x]=min(x,i);
			ansr[x]=max(x,i+(x-y));
		}
		printf("Case #%d:",cas++);
		for(int i=1;i<=n;i++){
			printf(" %d",ansr[i]-ansl[i]);
		}
		puts("");
	}
}
