#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
vector<int> e[101],v[2];
int in[101],a[101];
int x,y;
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n,m;
		scanf("%d%d",&n,&m);
		memset(in,0,sizeof(in));
		for(int i=0;i<=n;i++)
			e[i].clear();
		for(int i=0;i<m;i++){
			scanf("%d%d",&x,&y);
			e[x].push_back(y);
			e[y].push_back(x);
			in[x]++;
			in[y]++;
		}
		memset(a,0,sizeof(a));
		int sum=0;
		while(sum*2<m){
			int tmp=0,id=-1;
			for(int i=1;i<=n;i++)
			if(!a[i]){
				if(in[i]>tmp){
					tmp=in[i];
					id=i;
				}
			}
			sum+=tmp;
			a[id]=1;
			for(int i=0;i<e[id].size();i++){
				if(!a[e[id][i]]) in[e[id][i]]-=2; 
			}
		}
		v[0].clear();
		v[1].clear();
		for(int i=1;i<=n;i++)
			v[a[i]].push_back(i);
		for(int j=0;j<2;j++){
			printf("%d",v[j].size());
			for(int i=0;i<v[j].size();i++)
				printf(" %d",v[j][i]);
			puts("");
		}
	}
}
