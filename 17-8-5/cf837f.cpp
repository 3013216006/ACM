#include <iostream>
#include <string.h>
#include <algorithm>
#include <stdio.h>
using namespace std;
struct mat{
	int l;
	unsigned long long m[3][3];
};
int x;
unsigned long long a[200010];



mat mul(mat a,mat b){
	int l=a.l;
	mat ret;
	ret.l=l;
	memset(ret.m,0,sizeof(ret.m));
	for(int k=0;k<l;k++){
		for(int i=0;i<l;i++){
			for(int j=0;j<l;j++){
				ret.m[i][j]+=a.m[i][k]*b.m[k][j];
			}
		}
	}
	return ret;
}

mat getpow(mat a,long long k){
	mat ret;
	int l=a.l;
	ret.l=l;
	for(int i=0;i<l;i++){
		for(int j=0;j<l;j++){
			ret.m[i][j]=i==j;
		}
	}
	while(k){
		if(k&1) ret=mul(ret,a);
		k>>=1;
		a=mul(a,a);
	}
	return ret;
}

int main(){
	int n;
	long long m;
	while(~scanf("%d%lld",&n,&m)){
		int l=0;
		int flag=0;
		int mx=0;
		for(int i=0;i<n;i++){
			scanf("%d",&x);
			if(x||flag) a[l++]=x,flag=1;
			mx=max(mx,x);
		}
		if(mx>=m){
			puts("0");
			continue;
		}
		if(l>3){
		int ans=0;
			while(1){
				ans++;
				for(int i=1;i<l;i++)
					a[i]+=a[i-1];
				if(a[l-1]>=m) break;
			}
			cout << ans << endl;
		}
		else{
			long long ans=0;
			mat b;
			b.l=l;
			memset(b.m,0,sizeof(b.m));
			for(int i=0;i<b.l;i++)
				for(int j=i;j<b.l;j++)
					b.m[i][j]=1;
			mat tmp;
			long long L=0,r=1;
			while(1){
				tmp=getpow(b,r);
				unsigned long long t=0;
				for(int i=0;i<l;i++){
					t+=tmp.m[i][l-1]*a[i];
				}
				if(t>=m) break;
				else r=r*2;
			}
			while(L<=r){
				long long mid=L+r >> 1;
				tmp=getpow(b,mid);
				unsigned long long t=0;
				for(int i=0;i<l;i++){
					t+=tmp.m[i][l-1]*a[i];
				}
				if(t>=m) ans=mid,r=mid-1;
				else L=mid+1;
			}
			cout << ans << endl;
		}
	}

}
