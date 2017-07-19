#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int n,m,k;
long long mod=1000000007ll;
struct mat{
	long long a[13][13];
	void clear(){
		memset(a,0,sizeof(a));
	}
	void print(){
		for(int i=0;i<=m;i++){
			for(int j=0;j<=m;j++)
				printf("%lld ",a[i][j]);
			puts("");
		}
	}
};
mat mul(mat a,mat b){
	mat ret;
	ret.clear();
	for(int k=0;k<=m;k++)
		for(int i=0;i<=m;i++)
			for(int j=0;j<=m;j++)
				ret.a[i][j]+=a.a[i][k]*b.a[k][j]%mod;
	for(int i=0;i<=m;i++)
		for(int j=0;j<=m;j++)
			ret.a[i][j]%=mod;
	return ret;
}
mat myget(mat a,int k){
	mat ret;
	for(int i=0;i<=m;i++)
		for(int j=0;j<=m;j++)
			ret.a[i][j]=(i==j);
	while(k){
		if(k&1){
			ret=mul(ret,a);
		}
		a=mul(a,a);
		k>>=1;
	}
	return ret;	
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&m,&k);
		mat M;
		M.clear();
		for(int i=0;i<=m;i++)
			M.a[i][0]=k*(k-1);
		for(int i=1;i<=m;i++)
			M.a[i-1][i]=k;
		M=myget(M,n);
		long long ans1=0;
		for(int i=0;i<=m;i++)
			ans1+=M.a[0][i];
		ans1%=mod;
		M.clear();
		m--;
		for(int i=0;i<=m;i++)
			M.a[i][0]=k*(k-1);
		for(int i=1;i<=m;i++)
			M.a[i-1][i]=k;
		M=myget(M,n);
		for(int i=0;i<=m;i++)
			ans1=(ans1+mod-M.a[0][i])%mod;
		printf("%lld\n",ans1);
	}
}
