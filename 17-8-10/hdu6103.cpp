#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
char s[5500];


int main(){
	int T,m;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&m);
		scanf("%s",s);
		int l=strlen(s);
		int ans=0;
		int sum=0;
		for(int j=l-1;j>=0;j--){
			int r=j,r2=j,st=0;
			sum=0;
			for(int i=0;i<r;i++,r--){
				sum+=abs(s[i]-s[r]);
				while(sum>m) sum-=abs(s[st++]-s[r2--]);
				ans=max(ans,i-st+1);
			}
		}
		sum=0;
		for(int i=0;i<l-1;i++){
			int st=i,r=l-1;
			sum=0;
			for(int j=l-1,s1=i;s1<j;s1++,j--){
				sum+=abs(s[j]-s[s1]);
				while(sum>m) sum-=abs(s[st++]-s[r--]);
				ans=max(ans,s1-st+1);
			}
		}
		cout << ans << endl;
	}
}
