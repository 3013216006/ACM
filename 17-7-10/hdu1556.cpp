#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int t[100020];
int n,x,y;
int lowbit(int x){
	return x&(-x);
}

void add(int x,int op){
	while(x<=n){
		t[x]+=op;
		x+=lowbit(x);
	}
}
int query(int x){
	int ret=0;
	while(x){
		ret+=t[x];
		x-=lowbit(x);
	}
	return ret;
}
int main(){
	while(~scanf("%d",&n)){
		if(n==0) break;
		memset(t,0,sizeof(t));
		for(int i=0;i<n;i++){
			scanf("%d%d",&x,&y);
			add(x,1);
			add(y+1,-1);
		}
		for(int i=1;i<n;i++){
			printf("%d ",query(i));
		}
		printf("%d\n",query(n));
	}
}
