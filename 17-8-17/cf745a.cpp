#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
char s[100];
int main(){
	while(~scanf("%s",s)){
		int l=strlen(s);
		int ans=l;
		for(int i=1;i<l;i++){
			if(l%i) continue;
			int flag=1;
			for(int j=0;j<l;j++)
				if(s[j%i]!=s[j]) flag=0;
			if(flag){
				ans=i;
				break;
			}
		}
		cout << ans << endl;
	}
}
