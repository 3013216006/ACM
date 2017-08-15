#include <iostream>
#include <stdio.h>
#include<string.h>
using namespace std;
int a[10000010];

int main(){
	memset(a,0,sizeof(a));
	for(int i=2;i<=10000001;i++){
		if(a[i]) continue;
		for(int j=i+i;j<=10000001;j+=i)
			a[j]=1;
	}
	int n;
	while(~scanf("%d",&n)){
		for(int i=1;i<=100;i++){
			if(a[n*i+1]){
				cout << i << endl;
				break;
			}
		}
	}
}
