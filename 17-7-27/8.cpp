#include <iostream>
#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;
int a[110][110],t[110][10010];
deque<pair<int,int> > Q,Q1;

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n,m;
		scanf("%d%d",&n,&m);
		memset(t,-1,sizeof(t));
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				scanf("%d",&a[i][j]);
			}
		}
		long long ans=0;
		for(int j=0;j<m;j++){
			for(int i=0;i<n;i++){
				//cout << i<< "hehehe"  << j << endl;
				while(!Q.empty()) Q.pop_front();
				while(!Q1.empty()) Q1.pop_front();
				for(int k=0;k<=i;k++){
					int tmp=t[k][a[i][j]];
					while(!Q.empty()&&Q.back().first<=tmp) Q.pop_back();
					Q.push_back(make_pair(tmp,k));
				}
				for(int k=n-1;k>=i;k--){
					int tmp=t[k][a[i][j]];
					while(!Q1.empty()&&Q1.back().first<=tmp) Q1.pop_back();
					Q1.push_back(make_pair(tmp,k));
				}
				int l=n,pre=j,pre1=-1;
				while(!Q.empty()){
					if(Q.front().first>=Q1.front().first){
						ans+=1ll*(pre-Q.front().first)*(i-pre1)*(l-i)*(m-j);
						pre1=Q.front().second;
						pre=Q.front().first;
						Q.pop_front();
					}
					else{
						ans+=(pre-Q1.front().first)*(i-pre1)*(l-i)*(m-j);
//						cout << pre-Q.front().first << " " << i-pre1 << " " << l-i << " " << m-j << "aaaa" << endl;
						pre=Q1.front().first;
						l=Q1.front().second;
						Q1.pop_front();
					}
					//cout << ans << endl;
				}
				t[i][a[i][j]]=j;
				//cout << ans << endl;
			}
		}
		//cout << ans << endl;
		printf("%.9f\n",ans*1.0/(1ll*n*(n+1)/2*1ll*m*(m+1)/2));
	}
}
