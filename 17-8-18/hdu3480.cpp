#include <iostream>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
long long dp[11000][2];
int a[11000];

bool getans(int i,int j,int l,int k){
	return dp[i][l]+1ll*a[i+1]*a[i+1]-dp[j][l]-1ll*a[j+1]*a[j+1] >= 1ll*k*(a[i+1]-a[j+1]);
}

bool getans2(int i,int j,int k,int l){
	return (dp[i][l]+1ll*a[i+1]*a[i+1]-dp[j][l]-1ll*a[j+1]*a[j+1])*(a[j+1]-a[k+1])
	>= (dp[j][l]+1ll*a[j+1]*a[j+1]-dp[k][l]-1ll*a[k+1]*a[k+1])*(a[i+1]-a[j+1]);
}
deque<int> Q;
int main(){
	int T,cas=1;
	scanf("%d",&T);
	while(T--){
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		a[0]=0;
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++){
			dp[i][1]=(a[i]-a[1])*(a[i]-a[1]);
		}
		for(int j=2;j<=m;j++){
			int pre=(j-1)%2,nw=j%2;
			while(!Q.empty()) Q.pop_back();
			Q.push_back(j-1);
			for(int i=j;i<=n;i++){
				//cout << i << " - " << Q.size() << endl;
				//cout << Q.back() << endl;
				while(Q.size()>=2){
					int tp=Q.front();
					Q.pop_front();
					if(getans(tp,Q.front(),pre,a[i]*2)) continue;
					else{
						Q.push_front(tp);
						break;
					}
				}
				dp[i][nw]=dp[Q.front()][pre]+(a[i]-a[Q.front()+1])*(a[i]-a[Q.front()+1]);
				//cout << dp[Q.front()][pre] << endl;
				//cout << a[i] << " " << a[Q.front()] << endl;
				//cout << i << " " << Q.front() << endl;
				while(Q.size()>=2){
					int tp=Q.back();
					Q.pop_back();
					if(getans2(Q.back(),tp,i,pre)) continue;
					else{
						Q.push_back(tp);
						break;
					}
				}
				Q.push_back(i);
			}
		}
		printf("Case %d: ",cas++);
		cout << dp[n][m%2] << endl;
	}
}
