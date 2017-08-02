#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int pre[500001],nex[500001],sumpre[500001],sumnex[500001];
int a[500001],b[500001];
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			pre[i]=i-1;
			nex[i]=i+1;
			sumpre[i]=1;
			sumnex[i]=1;
			b[a[i]]=i;
		}
		m--;
		long long ans=0;
		for(int i=1;i<=n;i++){
			int x=b[i];
			int l=x,r=x;
			int k=m;
			while(k&&pre[l]){
				k--;
				l=pre[l];
			}
			while(l<=x){
				while(k&&nex[r]<=n){
					k--;
					r=nex[r];
				}
				if(k) break;
				ans+=1ll*sumpre[l]*sumnex[r]*a[x];
				l=nex[l];
				k++;
			}
				nex[pre[x]]=nex[x];
				pre[nex[x]]=pre[x];
				sumnex[pre[x]]+=sumnex[x];
				sumpre[nex[x]]+=sumpre[x];
		}
		cout << ans << endl;
	}
}
