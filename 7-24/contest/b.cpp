#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
char s[2000];
int a[200];
void myget(int &x,int &y){
	x=0,y=0;
	int i=0,l=strlen(s);
	while(s[i]!='/'){
		x=x*10+s[i]-'0';
		i++;
	}
	i++;
	while(i<l){
		y=y*10+s[i]-'0';
		i++;
	}
}

int main(){
	int T,n,m,cas;
	scanf("%d",&T);
	while(T--){
		int l=0;
		scanf("%d %s",&cas,s);
		myget(n,m);
		while(n!=m){
			if(n>m){
				a[l++]=1;
				n-=m;
			}
			else{
				a[l++]=0;
				m-=n;
			}
		}
		long long ans=1;
		for(int i=0;i<l;i++)
			ans=ans*2;
		long long tmp=0;
		for(int i=l-1;i>=0;i--)
			tmp=tmp*2+a[i];
		ans=ans+tmp;
		cout << cas << " " <<ans << endl;
	}
}
