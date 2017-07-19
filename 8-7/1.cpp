#include <iostream>
#include <stdio.h>
using namespace std;
int x;
int main(){
	int n;
	while(~scanf("%d",&n)){
		int ans=0;
		scanf("%d",&x);
		int t=x,l=x;
		for(int i=1;i<n;i++){
			scanf("%d",&x);
			if(x>t) ans++,t=x;
			if(x<l) ans++,l=x;
		}
		cout << ans << endl;
	}
}
