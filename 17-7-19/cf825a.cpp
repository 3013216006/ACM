#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
char s[100000];
int main(){
	int n;
	while(~scanf("%d",&n)){
		scanf("%s",s);
		int tmp=0;
		for(int i=0;i<n;i++){
			if(s[i]=='0') printf("%d",tmp),tmp=0;
			else tmp++;
		}
		cout << tmp << endl;
		puts("");
	}
}
