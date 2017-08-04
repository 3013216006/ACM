#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
int x,y;

int main(){
	int T,cas=1;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&x,&y);
		int ans=1;
		while(true){
			if(x>y) swap(x,y);
			int d=__gcd(x,y);
			long long tmp=1ll*y*d;
			long long tmp1=1ll*x+d;
			if(tmp%tmp1) break;
			y=tmp/tmp1;
			if(y%d) break;
			else ans++;
		}
		printf("Case #%d: %d\n",cas++,ans);
	}
}
