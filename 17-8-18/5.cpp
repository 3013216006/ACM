##include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

char s[1000];
long long dp1[1000][10],dp2[1000][10];
long long mod=1000000007ll;

int getans(){
	memset(dp1,0,sizeof(dp1));
	memset(dp2,0,sizeof(dp2));
	int l=strlen(s);
	int flag=0;
	for(int i=1;i<s[0]-'0';i++)
		dp1[0][i]=1;
	int tmp=s[0]-'0';
	long long sum=0;
	for(int i=1;i<l;i++){
		sum=sum*10%mod;
		//up
		for(int j=0;j<=9;j++){
			for(int k=0;k<j;k++){
				dp2[i][j]+=dp2[i-1][k]+dp1[i-1][k];
			}
			dp2[i][j]+=dp2[i-1][j];
		}
		//down
		for(int j=0;j<=9;j++){
			for(int k=9;k>j;k--){
				dp1[i][j]+=dp1[i-1][k];
				sum+=dp2[i-1][k];
			}
			dp1[i][j]+=dp1[i-1][j];
		}
		for(int j=1;j<=9;j++)
			dp1[i][j]++;
		if(flag==0){
			if(s[i]-'0'<=tmp){
				tmp=s[i]-'0';
				for(int j=0;j<tmp;j++)
					dp1[i][j]++;
			}
			else{
				flag=1;
				for(int j=0;j<=tmp;j++) dp1[i][j]++;
				for(int j=tmp+1;j<s[i]-'0';j++) dp2[i][j]++;
				tmp=s[i]-'0';
			}
		}
		else if(flag==1){
			if(s[i]-'0'<tmp){
				flag=2;
				sum+=s[i]-'0';
			}
			else{
				sum+=tmp;
				for(int j=tmp;j<s[i]-'0';j++) dp2[i][j]++;
				tmp=s[i]-'0';
			}
		}
		else{
			sum+=s[i]-'0';
		}
		sum%=mod;
		for(int j=0;j<=9;j++) dp1[i][j]%=mod,dp2[i][j]%=mod;
	}
	if(flag==2) sum++;
	long long ans=0;
	for(int i=0;i<l;i++){
		ans=(ans*10+s[i]-'0')%mod;
	}
	ans=(ans-sum+mod)%mod;
	return ans;
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%s",s);
		cout <<  getans() << endl;
	}
}
