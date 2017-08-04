#include <iostream>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
using namespace std;
int mx,my;
int t1[2010][2010],t2[2010][2010];
int mod=998244353;
int lowbit(int x){
	return x&(-x);
}

void add1(int x,int y,int v){
	if(v>=mod) v-=mod;
	for(int i=x;i<=my;i+=lowbit(i))
		for(int j=y;j<mx;j+=lowbit(j)){
			t1[i][j]+=v;
			if(t1[i][j]>=mod) t1[i][j]-=mod;
		}
}

void add2(int x,int y,int v){
	if(v>=mod) v-=mod;
	for(int i=x;i<=my;i+=lowbit(i))
		for(int j=y;j<mx;j+=lowbit(j)){
			t2[i][j]+=v;
			if(t2[i][j]>=mod) t2[i][j]-=mod;
		}
}

int query1(int x,int y){
	int ret=0;
	for(int i=x;i>0;i-=lowbit(i)){
		for(int j=y;j>0;j-=lowbit(j)){
			ret+=t1[i][j];
			if(ret>=mod) ret-=mod;
		}
	}
	return ret;
}


int query2(int x,int y){
	int ret=0;
	for(int i=x;i>0;i-=lowbit(i)){
		for(int j=y;j>0;j-=lowbit(j)){
			ret+=t2[i][j];
			if(ret>=mod) ret-=mod;
		}
	}
	return ret;
}
int a[2010],b[2010];
int ad1[2010],ad2[2010];
int main(){
	time_t st=clock();
	int T;
	int n,m;
	scanf("%d",&T);
	while(T--){
		mx=0;
		scanf("%d%d",&n,&m);
		memset(t1,0,sizeof(t1));
		memset(t2,0,sizeof(t2));
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			mx=max(mx,a[i]);
		}
		for(int i=1;i<=m;i++){
			scanf("%d",&b[i]);
			mx=max(mx,b[i]);
		}
		long long ans=0;
		mx++;
		my=m;
		int tmp1,tmp2;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++)
				if(a[i]==b[j]){
//					cout << i << " " << j << endl;
					tmp1=query1(j-1,a[i]-1);
					tmp2=query2(j-1,mx-a[i]-1);
					//add1(j,a[i],tmp2+1);
					//add2(j,mx-a[i],tmp1);
//					cout << j-1 << " " << mx-a[i]-1 << " " << endl;
					ad1[j]=tmp2+1;
					ad2[j]=tmp1;
//					cout << tmp1 << " "  <<  tmp2 << endl; 
					tmp1+=tmp2;
					tmp1++;
					tmp1%=mod;
					ans+=tmp1;
//					cout << i << " " << j << " " << ans << endl;
					//if(ans>=mod) ans-=mod;
				}
			for(int j=1;j<=m;j++){
				if(a[i]==b[j]){
					add1(j,a[i],ad1[j]);
					add2(j,mx-a[i],ad2[j]);
//					cout << j << " " << mx-a[i] << "-" << ad2[j] << endl;
				}
			}
		}
		cout << ans%mod << endl;
	}
	time_t en=clock();
	cout << (en-st)/CLOCKS_PER_SEC << endl;
}
