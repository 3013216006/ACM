#include <iostream>
#include <stdio.h>
using namespace std;
int n;
int x;
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		int a1=0,a2=0;
		for(int i=0;i<n;i++){
			scanf("%d",&x);
			if(x==1) a1++;
			if(x==2) a2++;
		}
		if(a1>a2) puts("Kobayashi");
		else if(a1==a2) puts("Draw");
		else puts("Tohru");
	}
}
