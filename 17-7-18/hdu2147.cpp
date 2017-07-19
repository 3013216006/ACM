#include <iostream>
#include <stdio.h>
using namespace std;

int main(){
	int n,m;
	while(scanf("%d%d",&n,&m),n&&m){
		int x=min(n,m),y=max(n,m);
		x--,y--;
		if(x&1) puts("Wonderful!");
		else if((y&1)==0) puts("What a pity!");
		else puts("Wonderful!");
	}
}
