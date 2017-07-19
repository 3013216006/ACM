#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <bitset>
#include <map>
#include <string.h>
#include <string>
#include <queue>
using namespace std;
string s1[200],s;
map<string,int> M;
bitset<200> a[100],b[100];
int vis[1000];
int main(){
	int T,n,m,k;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		scanf("%d",&k);
		M.clear();
		int cnt=0;
		for(int i=0;i<k;i++){
			cin >> s1[i];
			M[s1[i]]=i;
		}
		int k1=0;
		int x;
		for(int i=0;i<m;i++){
			scanf("%d",&k1);
			a[i].reset();
			for(int j=0;j<k1;j++){
				cin >> s;
//				cout << s << endl;
//				cout <<s << endl;
//				cout << M[s]  << endl;
				a[i][M[s]]=1;
			}
		}
		queue<int>  Q;
		memset(vis,0,sizeof(vis));
		for(int i=0;i<n;i++){
			b[i].reset();
			for(int j=0;j<k;j++)
				b[i][j]=1;
			for(int j=0;j<m;j++){
				scanf("%d",&x);
				if(x) b[i]&=a[j];
				else b[i]^=(a[j]&b[i]);
			}
			if(b[i].count()==1) Q.push(i),vis[i]=1;
		}
		while(!Q.empty()){
			int x=Q.front();
			Q.pop();
			for(int i=0;i<n;i++)
			if(!vis[i]&&((b[i]&b[x])==b[x])){
				b[i]^=b[x];
				if(b[i].count()==1) Q.push(i),vis[i]=1;
			}
		}
		for(int i=0;i<n;i++){
			if(vis[i]) {
				int ans=0;
				for(int j=0;j<k;j++)
					if(b[i][j]==1){
						ans=j;
						break;
					}
				cout << s1[ans] << endl;
			}
			else puts("Let's go to the library!!");
		}
	}
}
