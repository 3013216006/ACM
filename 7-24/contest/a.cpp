#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
long long c[50][50];
unsigned long long ans[100];
int cas,n;
int main(){
	int T;
	scanf("%d",&T);
	memset(c,0,sizeof(c));
	c[0][0]=1;
	for(int i=1;i<=40;i++){
		c[i][0]=1;
		for(int j=1;j<=i;j++)
			c[i][j]=c[i-1][j-1]+c[i-1][j];
	}
	ans[1]=0;
	for(int i=2;i<=50;i++){
		ans[i]=0;
		for(int j=i/2;j>=0;j--){
			int y=i-j*2;
			if(y>j) break;
			unsigned long long tmp=c[j+y][j];
//			cout << i << " " << tmp << endl;
			ans[i]+=tmp*tmp;
		}
	}
//	for(int i=1;i<=10;i++)
//		cout << ans[i] << endl;
	while(T--){
		scanf("%d%d",&cas,&n);
		if(n%2==1){
			printf("%d 0\n",cas);
			continue;
		}
		printf("%d %llu\n",cas,ans[n/2]);
	}
}
