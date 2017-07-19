#include <iostream>
#include <stdio.h>
#include <map>
#include <queue>
#include <string.h>
#include <algorithm>
using namespace std;
struct Node{
	int x,y;
};
struct Edge{
	int num,next;
}edge[20020];
map<string,int>M;
queue<Node> Q;
char s[2000],s1[2000];
int head[1100],cnt,mark[1100];
void add(int x,int y){
	edge[cnt].next=head[x];
	edge[cnt].num=y;
	head[x]=cnt++;
	edge[cnt].next=head[y];
	edge[cnt].num=x;
	head[y]=cnt++;
}
int main(){
	int n,m;
	while(scanf("%d",&n),n){
		cnt=0;
		M.clear();
		for(int i=0;i<n;i++){
			scanf("%s",s);
			M[s]=cnt++;
		}
		scanf("%d",&m);
		memset(head,-1,sizeof(head));
		cnt=0;
		for(int i=0;i<m;i++){
			scanf("%s%s",s,s1);
			add(M[s],M[s1]);
		}
		int ans=0;
		for(int i=0;i<n;i++){
			memset(mark,0,sizeof(mark));
			while(!Q.empty()) Q.pop();
			int tmp=0;
			Node x;
			x.x=i;
			x.y=0;
			Q.push(x);
			mark[i]=1;
			while(!Q.empty()){
				x=Q.front();
				Q.pop();
				tmp++;
				for(int i=head[x.x];i!=-1;i=edge[i].next){
					int v=edge[i].num;
					if(mark[v]) continue;
					Node tp;
					tp.x=v;
					tp.y=x.y+1;
					mark[v]=1;
					Q.push(tp);
				}
			}
			if(ans!=-1)
			ans=max(ans,x.y);
			if(tmp!=n) ans=-1;
		}
		printf("%d\n",ans);
	}
}
