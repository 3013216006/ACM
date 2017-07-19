#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
long long mod=1000000007ll;
struct mat{
	long long m[2][2];
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
	for(int i=0;i<2;i++)
		for(int j=0;j<2;j++)
			c.m[i][j]=0;
	for(int k=0;k<2;k++)
		for(int i=0;i<2;i++)
			for(int j=0;j<2;j++)
				c.m[i][j]+=a.m[i][k]*b.m[k][j]%mod;
	for(int i=0;i<2;i++)
		for(int j=0;j<2;j++)
			c.m[i][j]%=mod;
	return c;
}

mat myget(mat m,int k){
	mat ret; 
	for(int i=0;i<2;i++)
		for(int j=0;j<2;j++)
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
		scanf("%d%d",&x,&y);
		mat m;
		m.m[0][1]=0;
		m.m[1][1]=1;
		m.m[1][0]=y;
		m.m[0][0]=1;
		while(m.m[0][0]<=y) m.m[0][0]*=10;
		m.m[0][0]%=mod;
	//	print(m);
		m=myget(m,x);
	//	print(m);
		long long ans=m.m[1][0];
		cout << ans << endl;
	}
}
