#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int n;
char s[100100];
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		scanf("%s",s);
		int l=0,r=0;
		for(int i=0;i<n;i++){
			if(s[i]=='(') l++;
				else if(l) l--;else r++;
		}
		if(l==r&&l<=2){
			if(n==2&&l==0) puts("No");
				else puts("Yes");
		}
		else puts("No");
	}
}
