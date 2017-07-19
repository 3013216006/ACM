#include <iostream>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <set>
using namespace std;
struct Node{
	int num,next;
}edge[120000];
int cnt,head[200010];
set<int>::iterator it;
void add(int x,int y){
	edge[cnt].next=head[x];
	edge[cnt].num=y;
	head[x]=cnt++;
}
set<int> s;
vector<int> v[200010];
int d[200010],num[200010];
int main(){
	int n,m,T,x,y,S;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		memset(head,-1,sizeof(head));
		cnt=0;
		for(int i=0;i<m;i++){
			scanf("%d%d",&x,&y);
			add(x,y);
			add(y,x);
		}
		scanf("%d",&S);
		s.clear();
		memset(d,-1,sizeof(d));
		for(int i=0;i<n;i++){
			v[i].clear();
			s.insert(i+1);
		}
		if(n>m+1){
			for(int i=head[S];i!=-1;i=edge[i].next){
				d[edge[i].num]=2;
			}
			for(int i=1;i<=n;i++)
				if(d[i]==-1) d[i]=1;
		}
		else{
		v[0].push_back(S);
		d[S]=0;
		int sum=0;
		memset(num,0,sizeof(num));
		for(int i=0;i<n-1;i++){
			sum+=v[i].size();
			if(v[i].size()==0) break;
			for(int j=0;j<v[i].size();j++){
				int p=v[i][j];
				s.erase(p);
				for(int k=head[p];k!=-1;k=edge[k].next)
				if(d[edge[k].num]==-1){
					num[edge[k].num]++;
				}
			}
			for(it=s.begin();it!=s.end();it++){
				int l=*it;
				if(num[l]!=sum) v[i+1].push_back(l),d[l]=i+1;
			}
		}
		}
		int flag=0;
		for(int i=1;i<=n;i++)
			if(i!=S){
				if(flag) printf(" ");
				printf("%d",d[i]);
				flag=1;
			}
		puts("");
	}
}
