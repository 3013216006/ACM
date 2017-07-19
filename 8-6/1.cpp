#include <stdio.h>
#include <iostream>
using namespace std;
int x,y;
int main(){
	int n;
	while(~scanf("%d",&n)){
		int ans=0;
		for(int i=0;i<n;i++){
			scanf("%d%d",&x,&y);
			if(x<y) ans++;
				if(x>y) ans--;
		}
		if(ans>0) puts("Chris");
			else if(ans<0) puts("Mishka");
				else puts("Friendship is magic!^^");
	}
}
