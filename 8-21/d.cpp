#include <iostream>
using namespace std;

int getans(int l1,int r1,int l2,int r2){
	int ret=0;
	int sum=0;
	if(l1<=r1) sum+=suma[r1]-suma[l1-1];
	if(l2<=r2) sum+=suma[r2]-suma[l2-1];
	if(dp[l1][r1][l2][r2]) return dp[l1][r1][l2][r2];
	ret=max(ret)
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		suma[0]=0;sumb[0]=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			suma[i]=suma[i-1]+a[i];
		}
		for(int i=1;i<=n;i++){
			scanf("%d",&b[i]);
			sumb[i]=sumb[i-1]+b[i];
		}
		int ans=getans(1,n,1,n);
	}
}
