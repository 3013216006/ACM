#include <iostream>
#include <stdio.h>
#include <set>
#include <algorithm>
#include <string.h>
using namespace std;
set<int> S;
set<int> ::iterator it;
char s1[1000000],s2[1000000];
int main(){
	int T,cas=1;
	scanf("%d",&T);
	while(T--){
		S.clear();
		scanf("%s%s",s1,s2);
		int l1=strlen(s1),l2=strlen(s2);
		int l=min(l1,l2);
		for(int i=0;i<l;i++){
			if(s1[i]!=s2[i]) 
			S.insert(i);
		}
		S.insert(l);
		int m,op,x,y;
		char c[10];
		scanf("%d",&m);
		printf("Case %d:\n",cas++);
		while(m--){
			scanf("%d",&op);
			if(op==2){
				scanf("%d",&x);
				it=S.upper_bound(x-1);
				printf("%d\n",*it-x);
			}
			else{
				scanf("%d%d%s",&x,&y,c);
				if(s1[y]==s2[y]) op=1;
				else op=2;
				if(x==1) s1[y]=c[0];
				else s2[y]=c[0];
				if(s1[y]==s2[y]&&op==2) S.erase(y);
				if(s1[y]!=s2[y]&&op==1) S.insert(y);
			}
		}
	}
}
