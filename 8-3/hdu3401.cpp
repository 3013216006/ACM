#include <iostream>
using namespace std;

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&t,&n,&m);
		for(int i=0;i<t;i++)
			scanf("%d%d%d%d",&ap[i],&bp[i],&as[i],&bs[i]);
		memset(dp,0,sizeof(dp));
		dp[0][0][0]=1000*2000;
		for(int i=1;i<=t+m;i++){
			int k=i-m-1;
			k=max(k,0);
			int tot=1,rear=1;
			a[1]=max(dp[k][0][0],dp[k][0][1]);
			b[1]=0;
			for(int j=1;j<=n;j++){
				if(b[tot]<j-as[k]) tot++;
				dp[i][j][1]=a[tot]-j*ap[k];
				dp[i][j][0]=max(max(dp[i-1][j][0],dp[i][j][0]),dp[k][j][1]);
				int tmp=max(dp[k][j][0],dp[k][j][1])+j*ap[k];
				while(tot<=rear&&tmp>=a[rear]) rear--;
				rear++;
				a[rear]=tmp;
				b[rear]=j;
			}
			tot=n,rear=n;
			a[1]=max(dp[k][n][0],dp[k][n][1])+n*bp[i];
			b[1]=n;
			for(int j=n-1;j>=0;j--){
				if(b[tot]-bs[k]>j) tot++;
				dp[i][j][1]=a[tot]-j*bp[k];
				dp[i][j][0]=max(dp[i][j][0],max(dp[k][j][1],dp[i-1][j][0]));
				int tmp=max(dp[k][j][0],dp[k][j][1])+j*bp[k];
				while(tot<=rear&&tmp>=a[rear])rear--;
				rear++;
				a[rear]=tmp;
				b[rear]=j;
			}
		}
	}
}
