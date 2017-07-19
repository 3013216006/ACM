#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
int fa[1000001];
int vis[1000001],sum[1000001];
vector<int> c[1000001];
int find(int x){
	if(fa[x]==x) return x;
	else return fa[x]=find(fa[x]);
}

void add(int x,int y){
	cout << x << " " << y << endl;
	int fx=find(x),fy=find(y);
	if(fx==fy) return;
	else{
		fa[fx]=fy;
		sum[fy]+=sum[fx];
	}
}
int nm[1000010];
long long mod=1000000007ll;
void init(){
	nm[0]=1;
	for(int i=1;i<=1000000;i++)
		nm[i]=1ll*nm[i-1]*i%mod;
}
int a[1000001],b[1000001];
int tsum[1000001],tim[1000001];
int main(){
	init();
	int n,m,x,y;
	while(~scanf("%d%d",&n,&m)){
		for(int i=0;i<=m;i++){
			fa[i]=0;
		}
		memset(tim,0,sizeof(tim));
		sum[0]=m;
		int flag=1;
		for(int ii=0;ii<n;ii++){
			scanf("%d",&x);
			int l=0;
			for(int i=0;i<x;i++){
				scanf("%d",&y);
				if(a[y]>0) a[y]++;
				else a[y]=1,b[l++]=y,tim[y]++;
			}
			for(int i=0;i<l;i++){
				c[a[b[i]]].push_back(b[i]);
			}
			for(int i=0;i<l;i++){
				if(c[a[b[i]]].size()){
					int tmp=a[b[i]];
					vector<int> tmpfa;
					for(int j=0;j<c[tmp].size();j++){
						int v=c[tmp][j];
						if(vis[fa[v]]) tsum[fa[v]]++;
						else vis[fa[v]]=1,tsum[fa[v]]=1,tmpfa.push_back(fa[v]);
					}
					for(int j=0;j<c[tmp].size();j++){
						int v=c[tmp][j];
						if(vis[fa[v]]==1){
							if(tsum[fa[v]]==sum[fa[v]]) vis[fa[v]]=0;
							else vis[fa[v]]=-1,sum[flag]=tsum[fa[v]],sum[fa[v]]-=tsum[fa[v]],tsum[fa[v]]=flag++,fa[v]=tsum[fa[v]];
						}
						else if(vis[fa[v]]==-1){
							fa[v]=tsum[fa[v]];		
						}
					}
					for(int j=0;j<tmpfa.size();j++)
						vis[tmpfa[j]]=0,tsum[tmpfa[j]]=0;
					tmpfa.clear();
					c[tmp].clear();
				}
				a[b[i]]=0;
			}
//			for(int i=1;i<=m;i++)
//				cout << "i: " <<i << "="<< fa[i] << endl;
//			cout << "flag="  << flag << endl;
//			for(int i=0;i<flag;i++)
//				cout << sum[i] << endl;
		}
		long long ans=1;
		for(int i=0;i<flag;i++)
			ans=(ans*nm[sum[i]])%mod;	
		cout << ans << endl;
	}
}
