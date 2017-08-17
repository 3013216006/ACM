#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
char s[10000];

bool getnum(int &i,long long a,long long b){
	long long tmp;
	if(s[i]!='-') tmp=s[i]-'0';
	else tmp=0;
	int flag=0;
	if(s[i]=='0') if(s[i+1]!=' ') return 0;
	else return 1;
	if(s[i]=='-') flag=1;
	while(s[i+1]>='0'&&s[i+1]<='9'){
		if(flag) if(s[i+1]=='0') return 0;
		flag=0;
		i++;
		tmp*=10;
		tmp+=s[i]-'0';
		if(tmp<a||tmp>b) return 0;
	}
	return tmp>=a&&tmp<=b;
}

int main(){
	int n,m;
	while(gets(s)){
		scanf("%d%d",&n,&m);
		int l=strlen(s);
		long long tmp;
		int flag=1;
		for(int i=0;i<l&&flag;i++){
			if(s[i]==' ') continue;
			if(s[i]>='0'&&s[i]<='9'||s[i]=='-'){
				if(!getnum(i,n,m))flag=0;
			}
			else flag=0;
		}
		if(flag) puts("YES");
		else puts("NO");
		gets(s);
	}
}
