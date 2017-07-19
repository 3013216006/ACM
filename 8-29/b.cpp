#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
long long l[510],r[510],a[510][510];
int main(){
	int n;
	while(~scanf("%d",&n)){
		int x,y;
		memset(l,0,sizeof(l));
		memset(r,0,sizeof(r));
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++){
				scanf("%lld",&a[i][j]);
				if(a[i][j]==0) x=i,y=j;
				l[i]+=a[i][j];
				r[j]+=a[i][j];
			}
		if(n==1){
			puts("1");
			continue;
		}
		if(l[x]!=r[y]){
			puts("-1");
			continue;
		}
		long long ans=0;
		if(x==0)  l[x]=l[1];
		else l[x]=l[0];
		ans=l[x]-r[y],r[y]=l[x];
		a[x][y]=ans;
		long long sum1=0,sum2=0;
		for(int i=0;i<n;i++){
			sum1+=a[i][i];
			sum2+=a[i][n-i-1];
		}
		if(sum1!=sum2){
			ans=-1;
		}
		for(int i=0;i<n;i++){
			if(sum1!=l[i]) ans=-1;
			if(sum2!=r[i]) ans=-1;
		}
		ans=max(ans,-1ll);
		if(ans==0) ans=-1;
		printf("%lld\n",ans);
	}
}
