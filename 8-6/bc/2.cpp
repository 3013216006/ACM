#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;
priority_queue<int> Q;
int a[100100];
int b[100100];
int abs(int x){
	if(x<0) return -x;
	return x;
}

int main(){
	int T,n,cas=1;
	scanf("%d",&T);
	while(T--){
		while(!Q.empty()) Q.pop();
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
			if(i) Q.push(-abs(a[i]-a[i-1]));
			if(i>3) Q.pop();
			if(i) b[i]=abs(a[i]-a[i-1]);
		}
		int max3=0;
		if(n>3) {max3=-Q.top();Q.pop();}
		int max2=-Q.top();
		Q.pop();
		int max1=-Q.top();
		Q.pop();
		long long ans=0;
		if(abs(a[1]-a[0])==max1) ans+=max2;
			else ans+=max1;
		if(abs(a[n-1]-a[n-2])==max1) ans+=max2;
			else ans+=max1;
		for(int i=1;i<n-1;i++){
			int tmp=max1;
			if(b[i]==max1){
				if(b[i+1]==max2) tmp=max3;
					else tmp=max2;
			}
			else{
				if(b[i+1]==tmp){
					if(b[i]==max2) tmp=max3;
						else tmp=max2;
				}
			}
			ans+=max(tmp,abs(a[i-1]-a[i+1]));
		}
		printf("%lld\n",ans);
	}
}
