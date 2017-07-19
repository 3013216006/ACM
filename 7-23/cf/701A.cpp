#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int a[150],b[150][150];

int main(){
	int n,x;
	while(~scanf("%d",&n)){
		int sum=0;
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++){
			scanf("%d",&x);
			b[x][a[x]]=i;
			a[x]++;
			sum+=x;
		}
		sum=sum*2/n;
		for(int i=0;i<=100;i++)
			for(int j=0;j<a[i];j++){
				int tmp=sum-i;
				a[tmp]--;
				printf("%d %d\n",b[i][j],b[tmp][a[tmp]]);
			}
	}
}
