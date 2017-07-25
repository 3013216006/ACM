#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int main(){
	int n,cas=1;
	while(~scanf("%d",&n)){
		int ans=(int) (n/(log(10.0)/log(2.0))) ;
		printf("Case #%d: %d\n",cas++,ans);
	}
}
