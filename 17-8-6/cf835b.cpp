#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int k;
char s[100000];
int ans[100000];
int main(){
	while(~scanf("%d%s",&k,s)){
		int l=strlen(s);
		int sum=0;
		for(int i=0;i<l;i++){
			sum+=s[i]-'0';
			ans[i]='9'-s[i];
		}
		sort(ans,ans+l);
		int myans=0;
		int l1=l-1;
		while(sum<k){
			myans++;
			sum+=ans[l1--];
		}
		cout << myans << endl;
		continue;
	}
}
