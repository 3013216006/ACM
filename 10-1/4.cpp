#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int abs(int x){
	if(x<0) return -x;
		return x;
}
int main(){
	int T;
	scanf("%d",&T);
	int n,m,k,cas=1;
	while(~scanf("%d%d%d",&k,&n,&m)){
		int x=n,y=m,d=__gcd(n,m);
		int ans=0;
			ans=k/d;
		if(ans%2==0){
			printf("Case #%d: Iaka\n",cas++);
		}
		else{
			printf("Case #%d: Yuwgna\n",cas++);
		}
	}
}
