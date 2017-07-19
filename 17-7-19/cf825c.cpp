#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
int a[10200];
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	sort(a,a+n);
	int ans=0;
	int  now=k;
	for(int i=0;i<n;i++){
		while(a[i]>now*2) now=now*2,ans++;
		now=max(now,a[i]);
	}
	printf("%d\n",ans);
}
