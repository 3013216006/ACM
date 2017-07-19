#include <iostream>
#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;
struct Node{
	long long l,r;
	long long x;
	friend bool operator < (const Node &a,const Node &b){
		return a.x<b.x;
	}
};
priority_queue<Node> Q,P;
int main(){
	int n,m,x,y;
	while(~scanf("%d%d",&n,&m)){
		Node tmp;
		while(!Q.empty()) Q.pop();
		while(!P.empty()) P.pop();
		tmp.l=0,tmp.r=m,tmp.x=0;
		Q.push(tmp);
		for(int i=0;i<n;i++){
			scanf("%d%d",&x,&y);
			while(!Q.empty()){
				tmp=Q.top();
				Q.pop();
				P.push(tmp);
				tmp.l+=x;
				tmp.r+=x;
				tmp.x+=y;
				P.push(tmp);
			}
			int l=m+1;
			while(!P.empty()){
				tmp=P.top();
				P.pop();
				if(tmp.l>=l) continue;
				tmp.r=l-1;
				l=tmp.l;
				Q.push(tmp);
			}
		}
		printf("%lld\n",Q.top().x);
	}
}
