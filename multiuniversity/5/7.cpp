#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
long long dp[200000][20];
int pan[100000],a[25];

int is_0(int x,int t){
	if(x<t) return 0;
	x=x%t;
	if(x/(t/10)) return 0;
		else return 1;
}

long long myget(long long x,int k){
	int t=10;
	for(int i=2;i<k;i++)
		t*=10;
	int l=0;
	while(x>=t){
		a[l++]=x%10;
		x=x/10;
	}
	memset(dp,0,sizeof(dp));
	int flag=pan[x];
//	cout << x << "+++++++" << t<< endl;
	for(int i=0;i<x;i++){
		dp[i][l]=pan[i];
//		cout << i << " " <<l << " " << dp[i][l] << endl;
	}
	int cnt=0;
	while(l--){
		for(int i=0;i<t;i++)
			if(pan[i])
			for(int j=0;j<10;j++){
				int haha=i*10+j;
				if(pan[haha]) if(!is_0(haha,t)) {dp[(i*10+j)%t][l]+=dp[i][l+1];/*,cout << i << " " << j << " "<< dp[i][l+1] << endl;*/}
							else dp[(i*10+j)%t+t][l]+=dp[i][l+1];//,cout << i << " " << j << " " << dp[i][l+1] << "o"<< endl;
			}
		for(int i=t;i<=t+t/10;i++)
			if(pan[i-t])
				for(int j=1;j<10;j++)
					if(pan[(i*10+j)%t]) dp[(i*10+j)%t][l]+=dp[i][l+1];//,cout << i << " " << j << " " << dp[i][l+1] << endl;
		if(flag){
		//	cout << x << "_______________" << a[l]<< " " << t << endl;
			if(x>t){
				for(int i=1;i<a[l];i++)
					if(pan[(x*10+i)%t]) dp[(x*10+i)%t][l]+=1;//cout << i << " " << x <<  endl;
			}
			else
				for(int i=0;i<a[l];i++){
					int haha=x*10+i;
					//cout << haha << "**********" << endl;
					if(pan[haha]){
						//cout << haha << "+++++++++++++"<< endl;
						if(!is_0(haha,t)) dp[haha%t][l]+=1;
							else  dp[haha%t+t][l]+=1;
					}
				}
		}
		if(flag)
		if(x>=t) {
			x=(x*10+a[l])%t;
			if(a[l]==0) flag=0;
			else flag=min(flag,pan[x]);
		}
		else{
			x=x*10+a[l];
			flag=min(pan[x],flag);
			if(is_0(x,t)) {x=x%t+t;}
				else x=x%t;
		}
	}
	long long ret=0;
	if(flag) ret=1;//,cout << "haha" << endl;
	for(int i=0;i<=t+t/10;i++) ret+=dp[i][0];//cout << i << " " << dp[i][0] << endl;
	return ret;
}

int mypan(int x){
	if(pan[x/10]==0) return 0;
	int y=x%10;
	x/=10;
	while(x){
		if(x%10==y) return 0;
		x/=10;
	}
	return 1;
}

int main(){
	long long n,m;
	int k;
	pan[0]=1;
	for(int i=1;i<100000;i++)
		pan[i]=mypan(i);
	while(~scanf("%lld%lld%d",&n,&m,&k)){
		long long ans=myget(m,k);
	//	cout << ans << endl;
		ans-=myget(n-1,k);
		cout << ans << endl;
	}

}
