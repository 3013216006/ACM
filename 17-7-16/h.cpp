#include <iostream>
#include <stdio.h>
using namespace std;

int main(){
	int T,cas=1;
	scanf("%d",&T);
	while(T--){
		long long x,y;
		cin >> x >> y ;
//		scanf("%lld%lld",&x,&y);
//		cout << x << " " << y << endl;
		int ans=0;
		while(x>y){
			x=x/2+1;
			ans++;
		}
		printf("Case %d: %d\n",cas++,ans);
	}
}
