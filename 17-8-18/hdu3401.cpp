#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
using namespace std;
struct Node{
	int x;
	int y;
	Node(){}
	Node(int _x,int _y){
		x=_x,y=_y;
	}
};

deque<Node> Q1,Q2;
int dp[2010][2010];
int ap[2010],bp[2010],as[2010],bs[2010];

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n,m,k;
		scanf("%d%d%d",&n,&m,&k);
		k++;
		memset(dp,-1,sizeof(dp));
		dp[0][0]=2000000;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d%d",&ap[i],&bp[i],&as[i],&bs[i]);
			dp[i][0]=dp[0][0];
		}
		for(int i=1;i<=n;i++){
			int l=max((i-k),0),r=max((i+1-k),0);
			while(!Q1.empty()) Q1.pop_back();
			while(!Q2.empty()) Q2.pop_back();
			//Q1.push(Node(dp[i-1][0],0));
			for(int j=1;j<bs[i];j++)
				if(dp[l][j]!=-1){
					int tmp=dp[l][j]+j*bp[i];
					while(!Q2.empty()&&Q2.back().x<=tmp) Q2.pop_back();
					Q2.push_back(Node(tmp,j));
				}
			for(int j=0;j<=m;j++){
				dp[r][j]=max(dp[r][j],dp[l][j]);
				int tmp=-1;
				if(dp[l][j]!=-1)
					tmp=dp[l][j]+j*ap[i];
				while(!Q1.empty()&&Q1.front().y<j-as[i]) Q1.pop_front();
				if(tmp!=-1){
				while(!Q1.empty()&&Q1.back().x<=tmp) Q1.pop_back();
				Q1.push_back(Node(tmp,j));
				}
				if(j+bs[i]<=m&&dp[l][j+bs[i]]!=-1) tmp=dp[l][j+bs[i]]+(j+bs[i])*bp[i];
				else tmp=-1;
				while(!Q2.empty()&&Q2.front().y<=j) Q2.pop_front();
				if(tmp!=-1){
					while(!Q2.empty()&&Q2.back().x<=tmp) Q2.pop_back();
					Q2.push_back(Node(tmp,j+bs[i]));
				}
				if(!Q1.empty())
					dp[i][j]=max(dp[l][j],Q1.front().x-j*ap[i]);
				if(!Q2.empty())
					dp[i][j]=max(max(Q2.front().x-j*bp[i],dp[i][j]),dp[l][j]);
			}
		//	for(int i=0;i<=m;i++)
		//		printf("%d%c",dp[l][i]," \n"[i==m]);
		}
		int ans=0;
		for(int i=0;i<=m;i++)
			for(int j=0;j<=n;j++)
			ans=max(ans,dp[j][i]);
		cout << ans-2000000 << endl;
	}
}
