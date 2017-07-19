#include <iostream>
#include <stdio.h>
int n;
long long x;
using namespace std;

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		long long  ans=0;
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%lld",&x);
			if(x%8==0) x--;
			else if(x%8==7) x++;
			ans^=x;
		}
		if(ans==0) puts("Second player wins.");
		else puts("First player wins.");
	}
}
