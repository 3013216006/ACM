#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
set<int> s[55];
set<int>::iterator it;
vector<int> v[55];
int vis[55],flag[55];
int tmpans[55];
int dfs(int x){
	if(flag[x]) return 0;
	flag[x]=1;
	for(int i=0;i<v[x].size();i++){
		int V=v[x][i];
		if(vis[V]){
			if(dfs(vis[V])){
				vis[V]=x;
				return 1;
			}
		}
		else{
			vis[V]=x;
			return 1;
		}
	}
	return 0;
}

int dfs2(int x,int now){
	if(flag[x]) return 0;
	flag[x]=1;
	for(int i=0;i<v[x].size();i++){
		int V=v[x][i];
		if(vis[V]){
		if(vis[V]<now) continue;
			if(dfs2(vis[V],now)){
				vis[V]=x;
				tmpans[x]=V;
				return 1;
			}
		}
		else{
			vis[V]=x;
			tmpans[x]=V;
			return 1;
		}
	}
	return 0;
		
}

int main(){
	int n,x1,x2;
	int x,y,z;
	while(~scanf("%d%d%d",&n,&x1,&x2)){
		for(int i=1;i<=n;i++){
			s[i].clear();
			v[i].clear();
			for(int j=1;j<=n;j++){
				s[i].insert(j);
			}
		}
		for(int i=0;i<x1;i++){
			scanf("%d%d%d",&x,&y,&z);
			for(int j=1;j<x;j++){
				s[j].erase(z);
			}
			for(int j=x;j<=y;j++){
				for(int k=1;k<z;k++){
					s[j].erase(k);
				}
			}
			for(int j=y+1;j<=n;j++){
				s[j].erase(z);
			}
		}
		for(int i=0;i<x2;i++){
			scanf("%d%d%d",&x,&y,&z);
			for(int j=1;j<x;j++){
				s[j].erase(z);
			}
			for(int j=x;j<=y;j++){
				for(int k=z+1;k<=n;k++){
					s[j].erase(k);
				}
			}
			for(int j=y+1;j<=n;j++){
				s[j].erase(z);
			}
		}
		for(int i=1;i<=n;i++){
			for(it=s[i].begin();it!=s[i].end();it++){
			//	v[*it].push_back(i);
				v[i].push_back(*it);
			}
		}
		for(int i=1;i<=n;i++){
//			cout << endl;
//			cout << i << endl;
			sort(v[i].begin(),v[i].end());
//			for(int j=0;j<v[i].size();j++){
//				cout << v[i][j] << endl;
//			}
		}
		int ans=0;
		memset(vis,0,sizeof(vis));
//		for(int i=1;i<=n;i++){
		for(int i=n;i>=1;i--){
			memset(flag,0,sizeof(flag));
			if(dfs(i)) ans++;
		}
//		cout << ans << endl;
		if(ans!=n) puts("-1");
		else {
			for(int i=1;i<=n;i++){
				tmpans[vis[i]]=i;
			}
			for(int i=1;i<n;i++){
				memset(flag,0,sizeof(flag));
				vis[tmpans[i]]=0;
				dfs2(i,i);
			}
			for(int i=1;i<=n;i++){
				tmpans[vis[i]]=i;
			}
			for(int i=1;i<=n;i++){
				if(i>1) printf(" %d",tmpans[i]);
				else printf("%d",tmpans[i]);
			}
			puts("");
		}
	}
}
