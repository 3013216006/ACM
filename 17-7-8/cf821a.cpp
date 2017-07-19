#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int a[52][52];
int n;
int pan(int x,int y){
	for(int i=0;i<n;i++)
		if(a[x][i]<a[x][y])
		for(int j=0;j<n;j++)
			if(a[x][i]+a[j][y]==a[x][y]) 
				return 1;
	return 0;
}

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			scanf("%d",&a[i][j]);
	int flag=1;
	for(int i=0;i<n&&flag;i++)
		for(int j=0;j<n&&flag;j++)
			if(a[i][j]!=1) flag=pan(i,j);
	if(flag) puts("Yes");
	else puts("No");
}
