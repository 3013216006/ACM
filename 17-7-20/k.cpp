#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int v[5010],w[5010];
int op[5010];
int dp[5010][2048];
int pan(int x,int i){
	int tx=1<<(i-v[i]);
//	cout <<"in pan" <<  i << " " << v[i]  << " " << x << endl;
	if(x&tx){
		if(op[i]==1) return 1;
		if(op[i]==2) return 0;
		if(op[i]==3){
			if(x&(1<<(i-w[i]))) return 1;
			else return 0;
		}
		if(op[i]==4) return 1;
		if(op[i]==5){
			if(x&(1<<(i-w[i]))) return 0;
			else return 1;
		}
		if(op[i]==6) return 1;
	}
	else{
		if(op[i]==1) return 0;
		if(op[i]==2) return 1;
		if(op[i]==3) return 1;
		if(op[i]==4){
			if(x&(1<<(i-w[i]))) return 0;
			else return 1;
		}
		if(op[i]==5) return 1;
		if(op[i]==6){
			if(x&(1<<(i-w[i]))) return 1;
			else return 0;
		}
	}
}
char s[100],s1[100],s2[100];
int x,y,id;
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n,k;
		scanf("%d%d",&n,&k);
		for(int i=1;i<n;i++){
			scanf("%s%d:",s,&id);
			scanf("%s",s);
			if(s[0]=='P'){
				scanf("%d",&x);
				scanf("%s%s%s%s",s,s,s1,s);
				if(s1[0]=='b'){
					op[id]=2;
					v[id]=x;
				}
				else{
					op[id]=1;
					v[id]=x;
				}
			}
			else{
				scanf("%s%d",s,&x);
				scanf("%s%s%s%s",s,s,s1,s);
				scanf("%s%d%s%s%s%s",s,&y,s,s,s2,s);
				if(s1[0]=='b'&&s2[0]=='b'){
					op[id]=4;
					v[id]=x;
					w[id]=y;
				}
				else
				if(s1[0]=='g'&&s2[0]=='g'){
					op[id]=3;
					v[id]=x;
					w[id]=y;
				}
				else
				if(s1[0]=='g'&&s2[0]=='b'){
					op[id]=5;
					v[id]=x;
					w[id]=y;
				}
				else{
					op[id]=6;
					v[id]=x;
					w[id]=y;
				}
			}

		}
		k++;
		int l=1<<k;
/*		if(k==1){
			dp[1][0]=0;
			dp[1][1]=1;
			for(int i=1;i<n;i++){
				if(op[i+1]==1){
					dp[i+1][0]=max(dp[i][0],dp[i][1]);
					if(dp[i][1]!=-1)
					dp[i+1][1]=max(dp[i+1][1],dp[i][1]+1);
				}
				else{
					dp[i+1][0]=max(dp[i][0],dp[i][1]);
					dp[i+1][1]=max(dp[i+1][1],dp[i][0]+1);
				}
			}
			printf("%d\n",max(dp[n][0],dp[n][1]));
			continue;
		}*/
		int mod=1<<(k-1);
		memset(dp,-1,sizeof(dp));
		/*
		for(int i=0;i<l;i++){
			int flag=0;
			for(int j=2;j<=k;j++)
				if(i&(1<<(k-j)))
				if(!pan(i/(1<<(k-j)),j)) flag=1;
			if(flag==0){
				int tmp=i,ans=0;
				while(tmp){
					if(tmp&1) ans++;
					tmp>>=1;
				}
				dp[k][i]=ans;
			}
		}*/
		//dp[k][0]=0;
		dp[1][0]=0;
		dp[1][1]=1;
		for(int i=1;i<n;i++){
			for(int j=0;j<l;j++){
				//cout << i << " " << j << endl;
				if(dp[i][j]!=-1){
					int t=j%mod;
					t=t<<1;
					dp[i+1][t]=max(dp[i+1][t],dp[i][j]);
					//cout << i << " " << j << " " << t << endl;
					//cout << "hahah"  << (t|1) << " pan="  << pan(t,i+1)  << endl;
					if(pan(t|1,i+1))
						dp[i+1][t|1]=max(dp[i+1][t|1],dp[i][j]+1);
				}
			}
	//		for(int j=0;j<l;j++)
				//cout << "i = " << i << " j = " << j << " " << dp[i][j] << endl;
		}
		int ans=0;
		for(int i=0;i<l;i++)
			ans=max(ans,dp[n][i]);
		cout << ans << endl;
	}
}
