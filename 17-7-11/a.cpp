#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
char s[100010];
int a[200],b[200];
int main(){
	string	s1="Bulbasaur";
	while(~scanf("%s",s)){
		int l=strlen(s);
		int n=l;
		int l1=s1.length();
		int t=0,j=0;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		for(int i=0;i<n;i++){
			a[s[i]]++;
		}
		int ans=n;
		for(int i=0;i<l1;i++){
			b[s1[i]]++;
		}
		for(int i=0;i<l1;i++){
			ans=min(ans,a[s1[i]]/b[s1[i]]);
		}
		cout << ans << endl;
	}
}
