#include <iostream>
#include <stdio.h>
#include <queue>
#include <algorithm>
using namespace std;
struct Node{
	int l,v;
	Node(){}
	Node(int _l,int _v){
		l=_l,v=_v;
	}
};

deque<Node> Q; 
long long sum[50010];
int a[50010];
int dp[50010];
	int n,m;

int getans(int x,int y){
	if(x>=y) return n;
	int l=sum[y]-sum[x-1];
	l=n-l;
	int r=y-x;
	if(l%r) return l/r+1;
	else return l/r;
}

void mypush(int l,int v){
	while(!Q.empty()&&Q.back().v>=v) Q.pop_back();
	Q.push_back(Node(l,v));
}
int main(){
	while(~scanf("%d%d",&n,&m)){
		if(n==0&&m==0) break;
		sum[0]=0;
		for(int i=1;i<=m;i++){
			scanf("%d",&a[i]);
			sum[i]=sum[i-1]+a[i];
			dp[i]=n;
		}
		int i;
		for(i=2;i<=m;i++){
			if(sum[i]+i-1>n) break;
			dp[i]=getans(1,i);
		}
		int x=2;
		int l=2;
		while(!Q.empty()) Q.pop_front();
		for(i;i<=m;i++){
			while(sum[i]-sum[l-1]+i-l>n) l++;
			if(dp[l-1]==n) l++;
		//	while(x<l-1) mypush(x-1,dp[x-1]),x++;
			while(!Q.empty()&&Q.front().l<l-1) Q.pop_front();
			x=max(x,l);
			while((x<i-1&&dp[x-1]>getans(x,i))) mypush(x-1,dp[x-1]),x++;
			if(getans(x,i)==n){
				dp[i]=n;
				continue;
			}
			if(!Q.empty()){
				int tmp=getans(x,i);
				if(x==i-1) tmp=max(tmp,dp[x-1]);
				dp[i]=min(Q.front().v,tmp);
			}
			else dp[i]=max(getans(x,i),dp[x-1]);
		}
		int ans=dp[m];
		dp[0]=1;
		for(int j=m;j>0;j--){
			if(sum[m]-sum[j-1]+m-j<=n) ans=min(ans,dp[j-1]);
			else break;
		}
		cout << ans << endl;
	}
}
