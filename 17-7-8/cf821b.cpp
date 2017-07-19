#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int main(){
	int n,m;
	while(~scanf("%d%d",&n,&m)){
		long long ans=0;
		for(int i=0;i<m;i++){
			int j=n*(m-i);
			long long tmp=1ll*(i+j)*(i+1)*(j+1)/2;
			ans=max(ans,tmp);
		}
		cout << ans << endl;
		//printf("%lld\n",ans);
	}

}
