#include <iostream>
#include <stdio.h>

using namespace std;

long long mod=1000000007;
int main(){
	int n;
	while(~scanf("%d",&n)){
		long long ans=1;
		for(int i=0;i<n;i++){
			ans=ans*2%mod;
		}
		for(int i=1;i<=n;i++)
			ans=ans*i%mod;
		cout << ans << endl;
	}
}
