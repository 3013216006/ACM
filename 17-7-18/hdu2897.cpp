#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int main(){
	int n,p,q;
	while(~scanf("%d%d%d",&n,&p,&q)){
		if(n%(q+p)&&n%(p+q)<=p) puts("LOST");
		else puts("WIN");
	}
}
