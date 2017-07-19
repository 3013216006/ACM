#include <iostream>
#include <stdio.h>
using namespace std;

int main(){
	int n,m;
	while(~scanf("%d%d",&n,&m)){
		if(n<=3){
			if(m>=n-1) puts("T");
				else puts("F");
			continue;
		}
		else if(n<=4){
			if(m>=n) puts("T");
				else puts("F");
			continue;
		}/*
		else if(n<=5){
			if(m>=6) puts("T");
			else puts("F");
			continue;
		}*/
		else{
			long long a=n-3;
			a/=2;
			a*=(n/2);
			a+=n;
			if(n%2) a--;
			if(a<=m) puts("T");
				else puts("F");
				continue;
		}
	}
}
