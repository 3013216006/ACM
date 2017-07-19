#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int a[100100],b[100100];
int main(){
	int n,m;
	while(~scanf("%d%d",&n,&m)){
		long long sum1=0,sum2=0,ans=0;
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
			sum2+=a[i];
			if(i) ans+=a[i]*a[i-1];
		}
		ans+=a[n-1]*a[0];
		memset(b,0,sizeof(b));
		int x,y,z;
		for(int i=0;i<m;i++){
			scanf("%d",&x);
			y=x-1;
			z=(x-2+n)%n;
			x%=n;
			if(b[x]==0) ans-=a[y]*a[x];
			if(b[z]==0) ans-=a[z]*a[y];
			b[y]=1;
			ans+=sum1*a[y];
			sum1+=a[y];
			sum2-=a[y];
		}
		ans+=sum1*sum2;
		cout << ans << endl;
	}
}
