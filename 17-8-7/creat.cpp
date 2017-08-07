#include <iostream>
#include <stdio.h>
using namespace std;
long long mod=1000000007ll;
int main(){
	long long ans=1;
	for(int i=0;i<=1000000000;i++){
		if(i)
		ans=ans*i%mod;
		if(i%1000000==0){
			printf("v[%d]=%lld;\n",i/1000000,ans);
		}
	}
}
