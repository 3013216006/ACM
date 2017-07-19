#include <iostream>
#include <stdio.h>
using namespace std;
int n;

int main(){
	int T;
	int cas=1;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		long long tmp=1;
		int ans=0;
		while(tmp<n){
			ans++;
			n-=tmp;
			tmp<<=1;
		}
		ans++;
		printf("Case %d: %d\n",cas++,ans);
	}
}
