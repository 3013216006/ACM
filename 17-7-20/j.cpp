#include <iostream>
#include <vector>
#include <stdio.h>
#include <string.h>
using namespace std;
int b[800020];
int c[800020];
int cnt=0;
vector<int> v[800000];
void init(int n){
	for(int i=0;i<n;i++)
		v[i].clear();
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));
	for(int i=1;i<n;i++){
		for(int j=i;j<n;j+=i)
			v[j].push_back(i);
		long long t=1ll*i*i;
		if(t<n) c[t]=1;
	}

}

int vis[800000];
int main(){
	init(800000);
	int T;
	int m;
	scanf("%d",&T);
	while(T--){
		long long ans=0;
		scanf("%d",&m);
		int mk=1;
		memset(vis,0,sizeof(vis));
		for(int i=1;i*i<m;i++){
			int t=i*i;
			for(int j=t;j<m;j+=t){
				int tp=m-j;
				for(int k=0;k<v[tp].size();k++){
					if(vis[v[tp][k]]==mk) continue;
					else{
						ans++;
						vis[v[tp][k]]=mk;
					}
				}
			}
			mk++;
		}
		/*
		for(int i=0;i<cnt;i++){
			if(1ll*b[i]*b[i]+b[i]>m) break;
			if(m%b[i]==0){
				for(int j=b[i];j<=m;j+=b[i])
				if(c[j]){
					ans-=(m-b[i])/j-1;
					if((m-b[i])/j==1) ans--;
				}
			}
		}
		*/
		printf("%lld\n",ans);
	}
}
