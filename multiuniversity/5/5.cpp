#include <string.h>
#include <iostream>
#include <stdio.h>
using namespace std;
long long mod=1000000007ll;
char s[1000100],s1[2000200];
long long dp[2002000],dp1[1000100],dp2[1000100],dp3[2000200],dp4[2000200];
int main(){
	while(~scanf("%s",s)){
		int l=strlen(s);
		s1[0]='#';
		for(int i=0;i<l;i++){
			s1[i*2+1]=s[i];
			s1[i*2+2]='#';
		}
		memset(dp,0,sizeof(dp));
		dp[0]=1;
		long long x;
		for(int i=1;i<=l*2;i++){
			if(i>=dp[x]+x){
				dp[i]=1;
				while(i+dp[i]<=l*2&&i-dp[i]>=0&&s1[i+dp[i]]==s1[i-dp[i]]) dp[i]++;
				x=i;
			}
			else{
				int k=i-x;
				dp[i]=dp[x-k];
				if(i+dp[i]>x+dp[x]){
					dp[i]=x+dp[x]-i;
				}
				while(i+dp[i]<=l*2&&i-dp[i]>=0&&s1[i+dp[i]]==s1[i-dp[i]]) dp[i]++;
				if(i+dp[i]>x+dp[x]) x=i;
			}
		}
		int l1=l*2;
		x=0;
		long long sum=0;
		memset(dp3,0,sizeof(dp3));
		memset(dp2,0,sizeof(dp2));
		memset(dp1,0,sizeof(dp1));
		memset(dp4,0,sizeof(dp4));
		for(long long i=1;i<l1;i++){
			x++;
			sum+=i;
			dp3[i+dp[i]-1]+=i;
			dp3[i+dp[i]-1]%=mod;
			dp4[i+dp[i]-1]++;
			if(i%2){
				dp1[i/2]=sum+i/2*x%mod-i*x%mod+x;
			}
			else{
				x-=dp4[i];
				sum-=dp3[i];
				sum=(sum+mod)%mod;
			}
		}
		x=0,sum=0;
		memset(dp3,0,sizeof(dp3));
		memset(dp4,0,sizeof(dp4));
		for(long long i=l1;i>0;i--){
			x++;
			sum+=i;
			dp3[i-dp[i]+1]+=i;
			dp3[i-dp[i]+1]%=mod;
			dp4[i-dp[i]+1]++;
			if(i%2){
				dp2[i/2]=-i*x%mod+i/2*x%mod+sum+x;
			}
			else{
				x-=dp4[i];
				sum-=dp3[i];
				sum=(sum+mod)%mod;
			}
		}
		long long ans=0;
		for(int i=0;i<l-1;i++){
			ans+=dp1[i]*dp2[i+1]%mod;
			ans%=mod;
		}
		cout << ans << endl;
	}
}
