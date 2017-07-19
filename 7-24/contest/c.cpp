#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int euler[30001];

void getEuler(){
	memset(euler,0,sizeof(euler));
	euler[1]=1;
	for(int i=2;i<=10000;i++)
		if(!euler[i])
			for(int j=i;j<=10000;j+=i){
				if(!euler[j])
					euler[j]=j;
					euler[j]=euler[j]/i*(i-1);
			}
}

int main(){
	getEuler();
	euler[0]=1;
	for(int i=1;i<=10000;i++) euler[i]+=euler[i-1];
	int T,cas,n;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&cas,&n);
		printf("%d %d\n",cas,euler[n]);
	}
}
