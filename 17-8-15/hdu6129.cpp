#include <iostream>
#include <stdio.h>
using namespace std;
int a[200010];
int lowbit(int x){
	return x&(-x);
}

int main(){
	int T;
	int n,m;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++) scanf("%d",&a[i]);
		while(m){
			int x=lowbit(m);
			for(int i=x;i<n;i++)
				a[i]^=a[i-x];
				m-=x;
		}
		for(int i=0;i<n;i++)
			printf("%d%c",a[i]," \n"[i==n-1]);
	}
}
