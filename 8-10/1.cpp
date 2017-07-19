#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int main(){
	int T;
	long long x;
	scanf("%d",&T);
	while(T--){
		int sum=0;
		scanf("%lld",&x);
		while(x%2==0){
			sum++;
			x/=2;
		}
		if(sum%2==1) puts("Second Box");
			else puts("First Box");
	}
}
