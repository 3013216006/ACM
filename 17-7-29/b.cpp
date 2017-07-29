#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
int a[100010];
long long b[100010];

int main(){
	int n;
	while(~scanf("%d",&n)){
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		long long mod=1;
		long long ans=0;
		for(int i=0;i<9;i++){
			mod*=10;
			for(int i=0;i<n;i++){
				b[i]=a[i]%mod;
			}
			sort(b,b+n);
			for(int i=0;i<n;i++){
				int tmp=(lower_bound(b,b+n,mod-b[i])-b);
				if(tmp<=i) ans+=n-tmp-1;
				else ans+=n-tmp;
			}
		}
		cout << ans/2 << endl;
	}
}
