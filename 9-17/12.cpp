#include <iostream>
using namespace std;

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i].x);
			a[i].id=i;
		}
		sort(a+1,a+n+1,cmp);
		memset(dp,0,sizeof(dp));


	}
}
