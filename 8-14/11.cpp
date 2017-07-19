#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
char s[100100];
int a[100100];
int main(){
	int T,cas=1;
	scanf("%d",&T);
	while(T--){
		scanf("%s",s);
		int len=strlen(s);
		int l=0;
		for(int i=0;i<len;i++){
			int x=s[i]-'a'+1;
			int y=l;
			if(l!=0){
				y=lower_bound(a,a+l,x)-a;
			}
			y=min(l,y);
			while(y&&a[y]>=x) y--;
			y++;
			a[y]=x;
			l=max(l,y);
		}
		printf("Case #%d: %d\n",cas++,l);
	}
}
