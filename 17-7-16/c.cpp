#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
char s[1000];

int main(){
	int cas=1;
	int T;
	scanf("%d",&T);
	while(T--){
		int n,m;
		scanf("%d%d",&n,&m);
		int ans=0;
		for(int i=0;i<n;i++){
			scanf("%s",s);
			for(int j=0;j<m;j++){
				if(s[j]=='O') ans++;
			}
		}
		if(ans&1) 
			printf("Case %d: Maze\n",cas++);
		else 
			printf("Case %d: Fat brother\n",cas++);
	}
}
