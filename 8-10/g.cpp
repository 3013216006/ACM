#include <iostream>
#include <stdio.h>
using namespace std;
long long mod=1000000007ll;
int main(){
	int T,x,y;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&x,&y);
		long long ans=0,tmp=1;
		while(tmp<=y) tmp*=10;
		while(x--){
			ans=ans*tmp+y;
			ans%=mod;
		}
		cout << ans << endl;
	}
}
