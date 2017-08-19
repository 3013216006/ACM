#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
char s[1000010],s1[1000010];
int _next[1000010];
long long ans,add[1000010];
long long mod=1000000007ll;

void find(char *T,char *P,int *f){
	int n=strlen(T),m=strlen(P);
	int j=0;
	ans=0;
	for(int i=0;i<n;i++){
		while(j&&P[j]!=T[i]) j=f[j];
		if(P[j]==T[i]){
			ans=(ans+add[j])%mod;
			j++;
		}
		if(j==m) j=f[j];
	}
}

void getFail(char *P,int *f){
	memset(add,0,sizeof(add));
	int m=strlen(P);
	for(int i=0;i<m;i++)
		add[i]=i+1;
	f[0]=0;f[1]=0;
	for(int i=1;i<m;i++){
		int j=f[i];
		while(j&&P[i]!=P[j]) j=f[j];
		if(P[i]==P[j]){
			add[i]+=add[j];
			add[i]%=mod;
		}
		f[i+1]=P[i]==P[j]?j+1:0;
	}
}

void inv(){
	int l=strlen(s1);
	for(int i=0;i<l/2;i++){
		swap(s1[i],s1[l-i-1]);
	}
	l=strlen(s);
	for(int i=0;i<l/2;i++){
		swap(s[i],s[l-i-1]);
	}
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%s%s",s,s1);
		inv();
		getFail(s1,_next);
		find(s,s1,_next);
		cout << ans << endl;
	}

}
