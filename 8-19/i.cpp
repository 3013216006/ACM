#include <iostream>
#include <string.h>
#include <algorithm>
#include <stdio.h>
using namespace std;
char s[20];
int a[20],b[20];
int getans(char s){
	if(s=='A') return 16;
	if(s=='B') return 7;
	if(s=='C') return 8;
	if(s=='D') return 1;
	if(s=='E') return 1;
	if(s=='F') return 2;
	if(s=='G') return 3;
}

int main(){
	int T,cas=1;
	scanf("%d",&T);
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	while(T--){
		cas++;
		int ansn,ansm,n,m;
		scanf("%d",&n);
		ansn=0,ansm=0;
		for(int i=0;i<n;i++){
			scanf("%s",s);
			int t=getans(s[0]);
			a[t]=cas;
			ansn+=t;
		}
		if(a[7]!=cas||a[8]!=cas) ansn--;
		ansn=max(1,ansn);
		scanf("%d",&m);
		for(int i=0;i<m;i++){
			scanf("%s",s);
			int t=getans(s[0]);
			b[t]=cas;
			ansm+=t;
		}
		if(b[7]!=cas||b[8]!=cas) ansm--;
		ansm=max(1,ansm);
		if(ansn==ansm){
			puts("tie");
		}
		else if(ansn>ansm){
			puts("red");
		}
		else puts("black");
	}
}
