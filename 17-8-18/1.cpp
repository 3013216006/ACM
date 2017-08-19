#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

long long len,sum,l;
long long mod=1000000007ll;
char s[10000];
int _is(char c){
	if(c<='9'&&c>='0') return 1;
	else return 0;
}
int getnum(int &i){
		while(i<l&&_is(s[i])){
			len=len*10%mod;
			sum=(sum*10+s[i]-'0')%mod;
			i++;
		}
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%s",s);
		long long ans=0;
		l=strlen(s);
		for(int i=0;i<l;){
			if(s[i]=='('){
				len=1,sum=0;
				i++;
				getnum(i);
				i++;
				if(s[i]=='#'){
					i++;//(
					i++;
					int k=s[i]-'0';
					i++;//)
					i++;
					for(int i=0;i<k;i++)
						ans=(ans*len+sum)%mod;
				}
				else ans=(ans*len+sum)%mod;
			}
			else{
				len=1;
				sum=0;
				getnum(i);
				ans=(ans*len+sum)%mod;
			}
		}
		cout << ans << endl;
	}
}
