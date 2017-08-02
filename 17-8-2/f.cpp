#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
struct Node{
	int x,v;
	Node(){}
	Node(int _x,int _y){
		x=_x,v=_y;
	}
}fa[100010];

Node find(int x){
	if(fa[x].x==x) return fa[x];
	Node ret=find(fa[x].x);
	fa[x].x=ret.x;
	fa[x].v+=ret.v;
	return fa[x];
}


int main(){
	int n,m;
	char s[10];
	int x,y,v;
	while(~scanf("%d%d",&n,&m)){
		if(n==0&&m==0) break;
		for(int i=1;i<=n;i++){
			fa[i]=Node(i,0);
		}
		for(int i=0;i<m;i++){
			scanf("%s",s);
			scanf("%d%d",&x,&y);
			Node fax=find(x),fay=find(y);
			if(s[0]=='!'){
				scanf("%d",&v);
				if(fax.x==fay.x) continue;
				else{
					int tmp=fax.v-fay.v-v;
					if(tmp<0) fa[fax.x]=Node(fay.x,-tmp);
						else fa[fay.x]=Node(fax.x,tmp);
				}

			}
			else{
				if(fax.x==fay.x){
					cout << fax.v-fay.v << endl;
				}
				else{
					puts("UNKNOWN");
				}
			}
		}
	}
}
