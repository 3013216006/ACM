#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int pan(int x){
	if((x>>1)&x) return 0;
	if((x>>2)&x) return 0;
	return 1;
}

int count(int x){
	int ret=0;
	while(x){
		if(x&1) ret++;
		x>>=1;
	}
	return ret;
}
char c[15];
int s[66],num[66],dp[120][66][66],a[120];
int main(){
	int n,m;
	while(~scanf("%d%d",&n,&m)){
		int M=1<<m;
		int cnt=0;
		for(int i=0;i<M;i++)
			if(pan(i)) s[cnt]=i,num[cnt++]=count(i);

		for(int i=0;i<n;i++){
			scanf("%s",c);
			a[i]=0;
			for(int j=0;j<m;j++){
				a[i]=a[i]<<1;
				if(c[j]=='P') a[i]+=1;
			}
		}
		int ans=0;
		memset(dp,0,sizeof(dp));
		for(int i=0;i<cnt;i++)
			if((s[i]&a[0])==s[i])  ans=max(ans,num[i]),dp[0][0][i]=num[i];
		if(n>1){
			for(int i=0;i<cnt;i++)
				if((s[i]&a[1])==s[i])
					for(int j=0;j<cnt;j++)
						if((s[i]&s[j])==0)
							dp[1][i][j]=dp[0][0][j]+num[i];
			for(int i=2;i<n;i++){
				for(int l=0;l<cnt;l++)
					if((s[l]&a[i])==s[l]){
						for(int j=0;j<cnt;j++)
							if((s[l]&s[j])==0){
								for(int k=0;k<cnt;k++)
									if((s[l]&s[k])==0&&(s[j]&s[k])==0)
										dp[i][l][j]=max(dp[i][l][j],num[l]+dp[i-1][j][k]);
							}
					}
			}
		}
		for(int i=0;i<cnt;i++)
			for(int j=0;j<cnt;j++)
				ans=max(ans,dp[n-1][i][j]);

		printf("%d\n",ans);
	}
}
