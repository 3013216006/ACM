#include <iostream>
#include <stdio.h>
using namespace std;

int main(){
	int n;
	int x;
	while(~scanf("%d",&n)){
		int ans=0;
		for(int i=0;i<n;i++){
			scanf("%d",&x);
			if(x<=35) ans++;
		}
		cout << ans << endl;
	}
}
