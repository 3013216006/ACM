#include <iostream>
#include <math.h>

#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int ans1[1000010],ans[1000010];
int n=1000000;
int prime[1000010];
int mu[1000010];
long long mod=1000000007ll;
bool check[1000010];
int t[1000100];
int lowbit(int x){
	return x&(-x);
}

int add(int x){
	while(x<=n){
		t[x]++;
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

void init1(){
	int tmp;
	int pre,j;
	double tp;
	memset(t,0,sizeof(t));
	for(int i=2;i<=n;i++){
		add(i);
	 	for(int j=i+1;j<=n;j+=i)
			add(j);
	}
	for(int i=1;i<=n;i++)
		ans[i]=ans1[i]=query(i)+i;
}

void Moblus(){
	memset(check,false,sizeof(check));
	mu[1]=1;
	int tot=0;
	for(int i=2;i<=n;i++){
		if(!check[i]){
			prime[tot++]=i;
			mu[i]=-1;
		}
		for(int j=0;j<tot;j++){
			if(i*prime[j]>n) break;
			check[i*prime[j]]=true;
			if(i%prime[j]==0){
				mu[i*prime[j]]=0;
				break;
			}
			else{
				mu[i*prime[j]]=-mu[i];
			}
		}
	}
}

void init2(){
	for(int i=2;i<=n;i++)
	if(mu[i]){
		for(int j=i;j<=n;j+=i){
			ans[j]+=mu[i]*ans1[j/i];
		}
	}
}


int main(){
//	time_t st=clock();
	int T;
	init1();
//	time_t ed=clock();
//	cout << 1.0*(ed-st)/CLOCKS_PER_SEC << endl;
	Moblus();
//	ed=clock();
//	cout << 1.0*(ed-st)/CLOCKS_PER_SEC << endl;
	init2();
//	ed=clock();
//	cout << 1.0*(ed-st)/CLOCKS_PER_SEC << endl;
	ans[0]=0;
	for(int i=1;i<=n;i++){
		ans[i]+=ans[i-1];
		ans[i]%=mod;
	}
	
	while(~scanf("%d",&n)){
		printf("%d\n",ans[n]);
	}
}
