#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
int a[2000];
int main(){
	int n,x,y;
	while(~scanf("%d",&n)){
		memset(a,0,sizeof(a));
		for(int i=0;i<n;i++){
			scanf("%d%d",&x,&y);
			for(int i=x;i<=y;i++)
				a[i]=1;
		}
		int flag=1;
		int sum=0;
		for(int i=1;i<180;i++)
			sum+=a[i];
		for(int i=180;i<=1826;i++){
			sum+=a[i];
			if(sum>90) flag=0;
			sum-=a[i-180+1];
		}
		if(flag) puts("Yes");
			else puts("No");
	}
}
