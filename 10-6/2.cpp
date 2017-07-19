#include <iostream>
using namespace std;
bitset<10000> b[10010],tmp;

void dfs(int x){
	int l=v[x].size();
	tmp[x]=1;
	b[x]=tmp;
	for(int i=0;i<l;i++){
		int p=v[x][i];
		dfs(p);
	}
	tmp[x]=0;
	return ;
}
const maxn=;
struct Node{
	int num,next,id;
}edge[maxn];

int head[maxn],cnt;
bitset<10000> tp;
void add(int x,int y,int id){
	edge[cnt].next=head[x];
	edge[cnt].num=y;
	edge[cnt].id=id;
	head[x]=cnt++;
}

void dfs(int x){
	vis[x]=q;
	for(int i=head[x];i!=-1;i=edge[i].next){
		int id=edge[i].id;
		int 
	}
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=2;i<=m;i++){
			scanf("%d",&fa[i]);
			v[fa[i]].bush_back(i);
		}
		tmp.reset();
		dsf(1);
		memset(head,-1,sizeof(head));
		cnt=0;
		for(int i=1;i<=m;i++){
			scanf("%d%d",&x,&y);
			add(x,y,i);
			add(y,x,i);
		}
		scanf("%d",&q);
		memset(vis,-1,sizeof(vis));
		while(q--){
			scanf("%d",&k);
			tp.reset();
			for(int i=0;i<k;i++){
				scanf("%d",&x);
				tp|=b[x];
			}
			int ans=0;
			for(int i=1;i<=n;i++)
				if(vis[i]!=q){
					dfs(i);
					ans++;
				}
			printf("%d\n",ans);
		}
	}
}
