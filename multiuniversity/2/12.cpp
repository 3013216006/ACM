#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

void pre_ekmp(char x[],int m,int next[]){
	next[0]=m;
	int j=0;
	while(j+1<m&&x[j]==x[j+1])j++;
	next[1]=j;
	int k=1;
	for(int i=2;i<m;i++){
		int p=next[k]+k-1;
		int L=next[i-k];
		if(i+L<p+1) next[i]=L;
		else{
			j=max(0,p-i-1);
			while(i+j<m&&x[i+j]==x[j])j++;
			k=i;
			next[i]=j;
		}
	}
}

void ekmp(char x[],int m,char y[],int n,int next[],int extend[]){
	pre_ekmp(x,m,next);
	int j=0;
	while(j<n&&j<m&&x[j]==y[j]) j++;
	extend[0]=j;
	int k=0;
	for(int i=1;i<n;i++){
		int p=extend[k]+k-1;
		int L=next[i-k];
		if(i+L<p+1) extend[i]=L;
		else{
			j=max(0,p-i+1);
			while(i+j<n&&j<m&&y[i+j]==x[j]) j++;
			extend[i]=j;
			k=i;
		}
	}
}
int n,m;
int next[100010],extend[100010];
char s1[100010],s2[100010];
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		scanf("%s%s",s1,s2);
		ekmp(s2,m,s1,n,next,extend);
		for(int i=0;i<n;i++){
			if(i+m>n){
				printf("0");
				continue;
			}
			int flag=1;
			for(int j=extend[i];j<m&&flag;){
				if(s1[i+j]==s2[j]){
					j++;
					continue;
				}
				else{
					int y=j+1;
					if(y>=m){
						flag=0;
						j+=2;
						continue;
					}
					if(s1[i+j]==s2[y]&&s1[i+y]==s2[j]){
						j+=2;
					}
					else flag=0;
				}
			}
			printf("%d",flag);
		}	
		puts("");
	}
}
