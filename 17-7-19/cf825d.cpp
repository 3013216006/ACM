#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

char s[1000010],s1[1000010];
int sum1[30];
int main(){
	scanf("%s%s",s,s1);
	int l=strlen(s),l1=strlen(s1);
	int sum[30];
	memset(sum,0,sizeof(sum));
	memset(sum1,0,sizeof(sum1));
	for(int i=0;i<l1;i++){
		sum[s1[i]-'a']++;
	}
	int tmp=0;
	for(int i=0;i<l;i++){
		if(s[i]!='?')
			sum1[s[i]-'a']++;
		else tmp++;
	}
	int t=0;
	for(t=1;t<l+5;t++){
		int flag=0;

		for(int j=0;j<26;j++){
			if(sum[j]*t>=sum1[j]){
				flag+=(sum[j]*t-sum1[j]);	
			}
		}
		if(flag<=tmp) continue;
		else{
			t--;
			break;
		}
	}
	for(int i=0;i<26;i++)
		sum[i]*=t;
//		cout << t << endl;
	for(int i=0;i<l;i++){
		if(s[i]=='?'){
			for(int j=0;j<26;j++)
			if(sum1[j]<sum[j]){
				s[i]='a'+j;
				sum1[j]++;
				break;
			}
			if(s[i]=='?') s[i]='a';
		}
	}
	printf("%s\n",s);
}
