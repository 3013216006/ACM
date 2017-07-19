#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int l;
int a[100001],prime[100000];
int init(){
	int l=0;
	memset(a,0,sizeof(a));
	for(int i=2;i<=100000;i++)
		if(a[i]==0){
			a[i]=l;
			prime[l++]=i;
			for(long long j=1ll*i*i;j<=100000;j+=i)
				a[j]=1;
		}
	return l;
}
int vis[100000];
void add(int x){
	for(int i=0;i<l;i++){
		if(prime[i]*1ll*prime[i]>x) break;
		if(x%prime[i]==0) vis[i]++;
		while(x%prime[i]==0) x/=prime[i];
	}
	if(x!=1){
		vis[a[x]]++;
	}
}

int main(){
	l=init();
	int n,x;
	while(~scanf("%d",&n)){
		memset(vis,0,sizeof(vis));
		for(int i=0;i<n;i++){
			scanf("%d",&x);
			add(x);
		}
		int ans=1;
		for(int i=0;i<l;i++)
			ans=max(ans,vis[i]);
		cout << ans << endl;
	}
}
