#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
char s1[100],s2[100];
int mod=26;

int main(){
	int T,cas=1;
	scanf("%d",&T);
	while(T--){
		scanf("%s%s",s1,s2);
		int l1=strlen(s1);
		int l2=strlen(s2);
		if(l1!=l2){
			printf("Case #%d: NO\n",cas++);
			continue;
		}
		int sum=0;
		for(int i=0;i<l1;i++)
			sum+=s2[i]-s1[i];
		if(sum%2){
			printf("Case #%d: NO\n",cas++);
			continue;
		}
		if(l1==2){
			if((s1[1]-s1[0]+mod)%mod==(s2[1]-s2[0]+mod)%mod){
				if((s1[0]-s2[0]+mod)%mod%2==0){
					printf("Case #%d: YES\n",cas++);
					continue;
				}
			}
			if((s1[1]-s1[0]+mod)%mod==(s2[0]-s2[1]+mod)%mod){
				if((s1[0]-s2[1]+mod)%mod%2==1){
					printf("Case #%d: YES\n",cas++);
					continue;
				}
			}
			printf("Case #%d: NO\n",cas++);
		}
		else{
			printf("Case #%d: YES\n",cas++);
			continue;
		}
	}
}

