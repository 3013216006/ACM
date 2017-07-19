#include <iostream>
#include <string.h>
#include <algorithm>
#include <stdio.h>
using namespace std;
int n,a[20],sg[20],vis[20][20],hehe;
char s[20][20];
int cnt;
void work(int v,int x){
	sg[v]=0;
	while(vis[v][sg[v]]==x) sg[v]++;
	for(int i=0;i<cnt;i++)
		if(sg[a[i]]==0){
			if(s[v][a[i]]=='1'){
				vis[a[i]][sg[v]]=x;
			}
		}
	for(int i=0;i<cnt;i++)
		if(sg[a[i]]==0){
			if(s[v][a[i]]=='1'){
				work(a[i],x);
			}
		}
}

unsigned int getans(int x){
	unsigned int ret=0;
	cnt=0;
	for(int i=0;i<n;i++){
		if((1<<i)&x) a[cnt++]=i,sg[i]=0;
		
	}
	for(int i=0;i<cnt;i++)
	if(sg[a[i]]!=x){
		work(a[i],x);
	}
	for(int i=0;i<cnt;i++)
		if(sg[a[i]]>ret) ret=sg[a[i]];
	return ret+1;
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%s",s[i]);
		}
		int t=1<<n;
		unsigned int ans=0,tmp=1;
		memset(vis,0,sizeof(vis));
		hehe=0;
		for(int xx=1;xx<t;xx++){
			tmp*=233;
			unsigned int haha=getans(xx);
			ans+=haha*tmp;
		}
		cout << ans << endl;
	}
}
