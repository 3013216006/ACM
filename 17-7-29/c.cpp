#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
using namespace std;
char s[5000010],s1[5000010];
int _next[5000100];
int Q[5000100];
char Q1[5000100];
void get_next(){
	_next[0]=_next[1]=0;
	int l=strlen(s);
	for(int i=1;i<l;i++){
		int j=_next[i];
		while(j&&s[i]!=s[j]) j=_next[j];
		_next[i+1]=s[i]==s[j]?j+1:0;
	}
}

int Ql=-1;
void find(){
	int l=strlen(s),l1=strlen(s1);
	int j=0;
	Ql=-1;
	for(int i=0;i<l1;i++){
//		cout << i << " " << j << endl;
		while(j&&s[j]!=s1[i]) j=_next[j];
		if(s[j]==s1[i]) j++;
		if(j==l){
			Ql-=(l-1);
			//if(!Q.empty()) j=Q.back().second;
			if(Ql==-1) j=0;
			else j=Q[Ql];
		}
		else Q[++Ql]=j,Q1[Ql]=s1[i];
	}
}

void print(){
	Q1[Ql+1]='\0';
	printf("%s\n",Q1);
}

int main(){
	while(~scanf("%s%s",s,s1)){
		get_next();
		find();
		print();
	}
}
