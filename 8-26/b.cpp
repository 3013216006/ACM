#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
unsigned int dp[1000010];
int main(){
	int n,x,y;
	scanf("%d",&n);
	dp[0]=1;
	for(unsigned int i=1;i<=1000000;i++)
		dp[i]=dp[i-1]*i;
	while(n--){
		scanf("%d%d",&x,&y);
		cout << dp[x]/dp[y]/dp[x-y] << endl; 
	}
}
