#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int a[100100],b[100100],c[100100],d[100100],vis[100100];
long long mod=1000000007ll;
int main(){
	int n,m,cas=1;
	memset(c,0,sizeof(c));
	memset(d,0,sizeof(d));
	while(~scanf("%d%d",&n,&m)){
		for(int i=0;i<n;i++)
			scanf("%d",&a[i]);
		for(int i=0;i<m;i++)
			scanf("%d",&b[i]);
		memset(vis,0,sizeof(vis));
		long long ans=1;
		for(int i=0;i<m;i++)
		if(d[i]!=cas){
			int t=1,tp=i;
			while(b[tp]!=i) t++,tp=b[tp],d[tp]=cas;
			for(int j=t;j<=n;j+=t)
				vis[j]+=t;
		}
		for(int i=0;i<n;i++)
		if(c[i]!=cas){
			int t=1,tp=i;
			c[i]=cas;
			while(a[tp]!=i) t++,tp=a[tp],c[tp]=cas;
			ans=ans*vis[t]%mod;
		}
		printf("Case #%d: %lld\n",cas++,ans);
	}
}
