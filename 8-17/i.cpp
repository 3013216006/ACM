#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;
priority_queue<int> Q;
int in[200010];
vector<int> v[200010];
int ans[200010];
int main(){
	int n,m,x,y;
	while(~scanf("%d%d",&n,&m)){
		for(int i=1;i<=n;i++) v[i].clear();
		memset(in,0,sizeof(in));
		for(int i=0;i<m;i++){
			scanf("%d%d",&y,&x);
			in[y]++;
			v[x].push_back(y);
		}
		for(int i=1;i<=n;i++){
			if(in[i]==0) Q.push(i);
		}
		int haha=0;
		int cnt=0;
		while(!Q.empty()){
			x=Q.top();
			Q.pop();
			ans[cnt++]=x;
			for(int i=0;i<v[x].size();i++){
				y=v[x][i];
				in[y]--;
				if(in[y]==0) Q.push(y);
			}
		}
		for(int i=n-1;i>=0;i--)
			printf("%d ",ans[i]);
		puts("");
	}
}
