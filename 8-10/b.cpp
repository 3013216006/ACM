#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
long long mod=1000000007ll;
struct mat{
	long long m[3][3];
};

void print(mat a){
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++)
			cout << a.m[i][j] << " " ;
		cout << endl;
		}
}
mat mul(mat a,mat b){
	mat c;
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			c.m[i][j]=0;
	for(int k=0;k<3;k++)
		for(int i=0;i<3;i++)
			for(int j=0;j<3;j++)
				c.m[i][j]+=a.m[i][k]*b.m[k][j]%mod;
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			c.m[i][j]%=mod;
	return c;
}

mat myget(mat m,int k){
	mat ret; 
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			ret.m[i][j]=(i==j);
	while(k){
		if(k&1){
			ret=mul(ret,m);
		}
		m=mul(m,m);
		k/=2;
	}
	return ret;
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int x,y;
		scanf("%d",&x);
		mat m;
		m.m[0][0]=1;
		m.m[0][1]=2;
		m.m[0][2]=3;
		m.m[1][0]=4;
		m.m[1][1]=5;
		m.m[1][2]=6;
		m.m[2][0]=7;
		m.m[2][1]=8;
		m.m[2][2]=9;
		m=myget(m,x-1);
		long long ans=0;
		for(int i=0;i<3;i++)
			for(int j=0;j<3;j++)
				ans+=m.m[i][j];
		ans%=mod;
		cout << ans << endl;
	}
}
