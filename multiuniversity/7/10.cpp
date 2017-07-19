#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
#include <queue>
using namespace std;
struct Node{
	int x,y;
	friend bool operator<(const Node &a,const Node &b){
		return a.y<b.y;
	}
}tmp;
struct op{
	int x,y,z;
}a[10010];
priority_queue<Node> Q[2];
char s[10],s1[10];
int num[2],t[2];
int main(){
	int n,cas=1;
	while(~scanf("%d",&n)){
		if(n==0) break;
		printf("Case #%d:\n",cas++);
		while(!Q[0].empty()) Q[0].pop();
		while(!Q[1].empty()) Q[1].pop();
		int l=0,r=1;
		siz[l]=0,siz[r]=0;
		for(int i=0;i<n;i++){
			scanf("%s%s",s,s1);
			if(s[1]=='u'){
				a[i].x=0;
				a[i].y=0;
				if(s1[0]=='B') a[i].y=1;
				scanf("%d",&a[i].z);
			}
			else if(s[1]=='o'){
				a[i].x=1;
				a[i].y=0;
				if(s1[i]=='B') a[i].y=1;
			}
			else{
				scanf("%s",s1);
				a[i].x=2;
				if(s1[0]=='B'){
					a[i].y=0;
				}
				else{
					a[i].y=1;
				}
			}
		}

		for(int i=n-1;i>=0;i--){
				
		}
	}
}

