#include <iostream>
#include <stdio.h>
using namespace std;
int a[200200],b[200200],n,m,k,x;
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&m,&k);
		for(int i=0;i<n;i++){
			scanf("%d",&x);
			if(x>=m) a[i]=1;
				else a[i]=0;
			b[i]=0;
		}
		long long ans=0;
		for(int i=1;i<n;i++){
			if(a[i]) b[a[i-1]+1]=i+1;
			a[i]+=a[i-1];
		}
		if(a[0]) b[1]=1;
		for(int i=0;i<n;i++){
			if(a[i]>=k){
				ans+=b[a[i]-k+1];
			}
		}
		cout << ans << endl;
	}
}
