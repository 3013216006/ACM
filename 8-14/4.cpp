#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;
priority_queue<int> Q;
int main(){
	int T,cas=1,n,x;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		while(!Q.empty()) Q.pop();
		int sum=0;
		for(int i=0;i<n;i++){
			scanf("%d",&x);
			Q.push(x);
			sum+=x;
		}
		int ans=Q.top();
		sum-=ans;
		if(sum*3+2>=ans) printf("Case #%d: %d\n",cas++,(sum+ans)/2);
			else printf("Case #%d: %d\n",cas++,ans*2+1);
	}
}
