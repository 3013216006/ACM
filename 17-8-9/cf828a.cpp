#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int main(){
	int n,a,b;
	int c;
	int x;
	while(~scanf("%d%d%d",&n,&a,&b)){
		int c=0;
		int ans=0;
		for(int i=0;i<n;i++){
			scanf("%d",&x);
			if(x==2){
				if(b) b--;
				else ans+=2;
			}
			else{
				if(a) a--;
				else if(b) b--,c++;
				else if(c) c--;
				else ans++;
			}
		}
		cout << ans << endl;
	}
}
