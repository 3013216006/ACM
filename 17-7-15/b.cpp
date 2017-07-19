#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
int maxnum;
int a[100],n;
int pan(int n){
	if(a[0]!=a[1]||a[0]!=1){
//		cout << "wa1" << endl;
		return 0;
	}
	for(int i=0;i<n-1;i++){
		if(a[i+1]-a[i]>2&&a[i+1]!=maxnum){
//			cout << "wa2" << endl;
			return 0;
		}
	}
	return 1;
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		maxnum=0;
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
			maxnum=max(maxnum,a[i]);
		}
		if(n<10||n>13){
			puts("No");
			continue;
		}
		sort(a,a+n);
		int t=pan(n);
		if(t) puts("Yes");
		else puts("No");
	}
}
