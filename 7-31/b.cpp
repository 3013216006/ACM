#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int main(){
	int n,cas=1,a,b,p;
	scanf("%d",&p);
	while(~scanf("%d",&a),a){
		int ans=1,l=1;
		a%=p;
		scanf("%d",&b);
		b%=p;
		while(ans<p){
			l*=a;
			if(l>p) l%=p;
			if(l==b) break;
			if(l==1) break;
			ans++;
		}
		if(l==b) printf("%d\n",ans);
			else puts("0"),ans=0;
		cas++;
	}
}
