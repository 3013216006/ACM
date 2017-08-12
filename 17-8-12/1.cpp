#include <iostream>
#include <string.h>
#include <algorithm>
#include <stdio.h>
using namespace std;
long long p[1000100],a[1000100];
int pl;
int n;

void init(){
	pl=0;
	memset(a,0,sizeof(a));
	for(int i=2;i<=1000000;i++){
		if(a[i]==1) continue;
		

		p[pl++]=i;
		
		for(int j=i+i;j<=1000000;j+=i)
			a[j]=1;
	}
}


int main(){
	init();
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		n--;
		int ans=1;
		for(int i=0;i<pl;i++){
			if(n<p[i]*p[i]) break;
			if(n%p[i]==0){
				int t=1;
				while(n%p[i]==0) n/=p[i],t++;
				ans*=t;
			}
		}
		if(n!=1) ans*=2;
		cout << ans << endl;
	}
}
