#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string.h>
using namespace std;
int vis[10000];
int mu[10000];
int cnt;
int prime[10000];
void init(){
	memset(vis,0,sizeof(vis));
	cnt=0;
	mu[1]=1;
	for(int i=2;i<10000;i++){
		if(!vis[i]){
			prime[cnt++]=i;
			mu[i]=1;
		}
		for(int j=0;j<cnt&&i*prime[j]<10000;j++){
			vis[i*prime[j]]=1;
			if(i%prime[j]) mu[i*prime[j]]=-mu[i];
			else{
				mu[i*prime[j]]=0;
				break;
			}
		}
	}
}
int main(){
	init();
	int ans=0;
	int n,k;
	while(~scanf("%d%d",&n,&k)){
	long long tmp=1;
	for(int i=0;i<k;i++)
		tmp*=n;
		long long ans=0;
	for(long long i=1;i<=tmp;i++){
		ans+=mu[i]*mu[i]*(long long)(sqrt(tmp*1.0/i));
	}
	cout << ans << endl;
	}

}
