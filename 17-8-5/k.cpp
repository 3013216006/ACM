#include <iostream>
#include <stdio.h>
#include <string.h>
#include <queue>
#include <algorithm>
using namespace std;
struct Node{
	int v,next;
}edge[300010];
struct Node1{
	int l,r;
}b[300010];
struct Node2{
	int id,size,st;	
}a[300010];
int now;
int head[300010];
int cnt;
int siz[300100];


bool cmp(Node2 a,Node2 b){
	return a.size>b.size;
}

void add(int x,int y){
	edge[cnt].next=head[x];
	edge[cnt].v=y;
	head[x]=cnt++;
}

void dfs(int x){
	int siz=0;
	if(head[x]==-1){
		now++;
		b[x].l=now;
		b[x].r=now;
		return;
	}
	b[x].l=now+1;
	for(int i=head[x];i!=-1;i=edge[i].next){
		int v=edge[i].v;
		dfs(v);
	}
	b[x].r=now;
}

queue<int> Q[300010];
int sum[300100];
int getans(int x){
	if(siz[x])
	Q[b[x].l].push(x);
	if(head[x]==-1) return siz[x];
	if(sum[x]!=0) return siz[x];
	int ans=300000;
	for(int i=head[x];i!=-1;i=edge[i].next){
		int v=edge[i].v;
		ans=min(ans,getans(v));
	}
	return ans+siz[x];
}
int vis[300100];
vector<int> v[300100];
queue<int> Q1[300100];
int ansq[300100];
int main(){
	int n,m,k;
	int l;
	while(~scanf("%d%d%d",&n,&m,&k)){
		memset(sum,0,sizeof(sum));
		for(int i=1;i<=m;i++){
			scanf("%d",&l);
			v[i].resize(l);
			for(int j=0;j<l;j++){
				scanf("%d",&v[i][j]);
			}
			sort(v[i].begin(),v[i].end());
			a[i].id=i;
			a[i].size=l;
			a[i].st=v[i][0];
			while(!Q[i].empty()) Q[i].pop();
		}
		sort(a+1,a+m+1,cmp);
		memset(vis,0,sizeof(vis));
		memset(head,-1,sizeof(head));
		cnt=0;
		sum[0]=n;
		for(int i=1;i<=m;i++){
			sum[vis[a[i].st]]-=a[i].size;
			sum[a[i].id]=a[i].size;
			add(vis[a[i].st],a[i].id);
			for(int j=0;j<a[i].size;j++)
				vis[v[a[i].id][j]]=a[i].id;
			while(!Q[i].empty()) Q[i].pop();
			while(!Q1[i].empty()) Q1[i].pop();
		}
		now=0;
		dfs(0);
		int x;
		memset(siz,0,sizeof(siz));
		for(int i=0;i<k;i++){
			scanf("%d",&x);
			Q1[x].push(i+1);
			siz[x]++;
		}
		int flag=1;
		for(int i=1;i<=n;i++)
			if(vis[i]==0) flag=0;
		if(flag==0){
			puts("0");
			continue;
		}
		int ans=getans(0);
		cout << ans << endl;
		int tmp;
		for(int xx=0;xx<ans;xx++){
			int suml=0;
			int st=1;
			while(st<=b[0].r){
//				cout << st << endl;
				tmp=Q[st].front();
				siz[tmp]--;
				if(siz[tmp]==0) Q[st].pop();
				ansq[suml++]=Q1[tmp].front();
				Q1[tmp].pop();
				st=b[tmp].r+1;
			}
			printf("%d",suml);
			for(int i=0;i<suml;i++)
				printf(" %d",ansq[i]);
			puts("");
		}
	}
}
