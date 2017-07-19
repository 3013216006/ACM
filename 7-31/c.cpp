#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
char s[200];
int main(){
	int T,n;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		scanf("%s",s);
		int ans=0,l=0,r=0;
		for(int i=0;i<n;i++){
			if(s[i]=='(') l++;
			else{
				if(l) l--,r++;
				else ans++,l++;
			}
		}
		ans+=l/2;
		printf("%d\n",ans);
	}
}
