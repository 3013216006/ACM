#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <map>
using namespace std;

map<long long,int> M;
int st,ans[5000000],ansl,b[10];
long long ed=0;
char s[10][10],s1[10][10];

long long change(long long p,int op){
	int a[9],p_zero;
	for(int i=8;i>=0;i--){
		a[i]=p%9;
		p/=9;
		if(a[i]==0) p_zero=i;
	}
	//u
	if(op==0){
		if(p_zero-3>=0)
			swap(a[p_zero],a[p_zero-3]);
	}
	//d
	if(op==1){
		if(p_zero+3<9)
			swap(a[p_zero],a[p_zero+3]);
	}
	//l
	if(op==2){
		if(p_zero%3){
			swap(a[p_zero],a[p_zero-1]);
		}
	}
	//r
	if(op==3){
		if((p_zero+1)%3){
			swap(a[p_zero],a[p_zero+1]);
		}
	}
	for(int i=0;i<9;i++)
		p=p*9+a[i];
	return p;
}

int dfs(long long p){
	if(p==ed) return 1;
	if(M.count(p)>0) return 0;
	M[p]=1;
	for(int i=0;i<4;i++){
		ans[ansl++]=i;
		if(dfs(change(p,i))) return 1;
		ansl--;
	}
	return 0;
}


void init(){
	s1[0][0]='u';s1[0][1]='\0';
	s1[1][0]='d';s1[1][1]='\0';
	s1[2][0]='l';s1[2][1]='\0';
	s1[3][0]='r';s1[3][1]='\0';
}

int main(){
	init();
	for(int i=1;i<=8;i++)
		ed=ed*9+i;
	ed*=9;
	while(~scanf("%s",s[0])){
		//in
		for(int i=1;i<9;i++) 
			scanf("%s",s[i]);
		for(int i=0;i<9;i++){
			if(s[i][0]=='x') st=i,b[i]=0;
			else b[i]=s[i][0]-'0';
		}

		//init
		M.clear();
		ansl=0;
		long long p=0;
		for(int i=0;i<9;i++)
			p=p*9+b[i];
		
		//bfs
		if(dfs(p)==0) puts("unsolvable");
		else{
			for(int i=0;i<ansl;i++){
				printf("%s",s1[ans[i]]);
			}
			puts("");
		}
	}
	
}
