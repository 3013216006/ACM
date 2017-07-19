#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int cnt=0,b[100100],a[100100];
char s[50];
int prim[100100];
void rm(int x){
	int y=x;
	for(int i=0;prim[i]*prim[i]<=x&&i<cnt;i++)
		if(x%prim[i]==0){
			if(b[prim[i]]==y)
			b[prim[i]]=0;
			while(x%prim[i]==0){
				x/=prim[i];
			}
		}
	if(x!=1) if(b[x]==y) b[x]=0;
}
void work(int x,int flag){
	if(a[x]){
		if(flag==1){
			puts("Already on");
			return;
		}
	}
	else{
		if(flag==-1){
			puts("Already off");
			return;
		}
	}
	int y=x;
	if(flag==1){
		for(int i=0;prim[i]*prim[i]<=x&&i<cnt;i++)
		if(x%prim[i]==0){
			if(b[prim[i]]){
				printf("Conflict with %d\n",b[prim[i]]);
				rm(y);
				return;
			}
			while(x%prim[i]==0) x/=prim[i];
			b[prim[i]]=y;
		}
		if(x!=1){
			if(b[x]){
				printf("Conflict with %d\n",b[x]);
				rm(y);
				return;
			}
			b[x]=y;
		}
	}
	else rm(x);
	puts("Success");
	if(flag==1) a[y]=1;
	else a[y]=0;
}

int main(){
	int n,m;
	memset(prim,0,sizeof(prim));
	for(int i=2;i<100000;i++)
	if(!prim[i]){
		prim[cnt++]=i;
		for(int j=i+i;j<100000;j+=i)
			prim[j]=1;
	}
	while(~scanf("%d%d",&n,&m)){
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		for(int i=0;i<m;i++){
			scanf("%s",s);
			int flag=1;
			if(s[0]=='-') flag=-1;
			int x;
			scanf("%d",&x);
			work(x,flag);
		}
	}
}
