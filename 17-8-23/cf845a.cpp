#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int a[2000];

int main(){
	int n;
	while(~scanf("%d",&n)){
		n*=2;
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		sort(a,a+n);
		int sum=0;
		for(int i=0,r=n/2;i<r;i++,r++){
			if(a[i]<a[r]) sum++;
			else sum--;
		}
		if(sum>0) puts("Yes");
		else puts("No");
	}
}
