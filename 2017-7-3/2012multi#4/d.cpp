#include <iostream>
#include <stdio.h>
#include <map>
using namespace std;
map<long long,int> M,M1;
long long a[5][201];
bool pan(int n){
	M1.clear();
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++){
			long long x=a[2][i]+a[1][j];
			//if(M1.count(x)>0) continue;
			//M1[x]=1;
			for(int k=0;k<n;k++){
				if(M.count(a[0][k]+x)>0) return 1;
			}
		}
	return 0;
}

int main(){
	int T,n;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=0;i<5;i++)
			for(int j=0;j<n;j++)
				scanf("%lld",&a[i][j]);
		M.clear();
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				M[-a[3][i]-a[4][j]]=1;
		if(pan(n)) puts("Yes");
		else puts("No");
	}
}
