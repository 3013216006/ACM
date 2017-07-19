#include <iostream>
#include <stdio.h>
using namespace std;
int a[100010];
int main(){
	int n;
	while(~scanf("%d",&n)){
		int ans=1,l=1;
		scanf("%d",&a[0]);
		for(int i=1;i<n;i++){
			scanf("%d",&a[i]);
			if(a[i]>a[i-1]) l++;
				else l=1;
			ans=max(ans,l);
		}
		printf("%d\n",ans);
	}
}
