#include <iostream>
#include <stdio.h>
using namespace std;

int main(){
	int s,v1,v2,t1,t2;
	while(~scanf("%d%d%d%d%d",&s,&v1,&v2,&t1,&t2)){
		int ans1=v1*s+t1*2;
		int ans2=v2*s+t2*2;
		if(ans1<ans2) puts("First");
		else if(ans1==ans2) puts("Friendship");
		else puts("Second");
	}
}
