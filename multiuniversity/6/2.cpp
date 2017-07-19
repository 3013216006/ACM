#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
using namespace std;
struct Node{
	int num,next;
}edge[40100];
int head[110],cnt;
int in[110];
struct Node1{
	long long x,y;
}a[110];
void add(int x,int y){
	edge[cnt].num=y;
	edge[cnt].next=head[x];
	head[x]=cnt++;
	edge[cnt].num=x;
	edge[cnt].next=head[y];
	head[y]=cnt++;
}
long long ans[110];
long long p=110119,mod;
long long mypow(long long x,int y){
	long long ret=1;
	while(y){
		if(y&1){
			ret*=x;
			ret%=mod;
		}
		x*=x;
		x%=mod;
		y>>=1;
	}
	return ret;
}
long long b[110119],ni[110119];
int init(){
	mod=p;
	b[0]=1;
	ni[0]=1;
	for(long long i=1;i<p;i++){
		b[i]=b[i-1]*i%p;
		ni[i]=mypow(b[i],p-2);
	}
}

long long cal(long long x,long long y){
	if(x>y) return 0;
	if(y==0) return 1;
	long long ret=b[y];
	ret=ret*ni[y-x]%p*ni[x];
	ret%=p;
	return ret;
}

long long lucas(long long x,long long y){
	if(y==0) return 1;
	long long ret=cal(x%p,y%p);
	ret*=lucas(x/p,y/p);
	ret%=p;
	return ret;
}

long long getans(long long n,long long m){
	if((n+m)%3) return 0;
	long long x=n-(n+m)/3;
	long long y=n+m;
	y/=3;
	if(x<0||y<x) return 0;
	if(y-x<x) x=y-x;
	return lucas(x,y);
}

int main(){
	long long n,m;
	int k,cas=1;
	init();
	while(~scanf("%lld%lld%d",&n,&m,&k)){
		memset(in,0,sizeof(in));
		memset(head,-1,sizeof(head));
		cnt=0;
		for(int i=0;i<k;i++)
			scanf("%lld%lld",&a[i].x,&a[i].y);
		for(int i=0;i<k;i++)
			for(int j=0;j<i;j++){
				if(a[i].x<a[j].x&&a[i].y<a[j].y){
					add(j,i);
					in[j]++;
				}
				if(a[i].x>a[j].x&&a[i].y>a[j].y){
					add(i,j);
					in[i]++;
				}
			}
		queue<int> Q;
		for(int i=0;i<k;i++){
			if(in[i]==0) Q.push(i);
			ans[i]=getans(a[i].x-1,a[i].y-1);
		}
		while(!Q.empty()){
			int tmp=Q.front();
			int tx=a[tmp].x,ty=a[tmp].y;
			Q.pop();
			for(int i=head[tmp];i!=-1;i=edge[i].next){
				int v=edge[i].num;
				if(a[tmp].x<a[v].x){
					in[v]--;
					if(in[v]==0) Q.push(v);
				}
				else{
					ans[tmp]-=ans[v]*getans(a[tmp].x-a[v].x,a[tmp].y-a[v].y)%mod;
					if(ans[tmp]<0) ans[tmp]+=mod;
				}
			}
		}
		long long myans=getans(n-1,m-1);
		for(int i=0;i<k;i++){
			myans-=ans[i]*getans(n-a[i].x,m-a[i].y)%mod;
			if(myans<0) myans+=mod;
		}
		printf("Case #%d: %lld\n",cas++,myans);
	}
}
