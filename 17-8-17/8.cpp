#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int a[1100];
char s[100];
int main(){
	int T,n,m;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		int sum1=0,sum2=0;
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		for(int i=0;i<n;i++){
			scanf("%s",s);
			if(s[0]=='N') sum1+=a[i],sum2-=a[i];
			else if(s[0]=='L') sum1+=a[i];
			else sum2-=a[i];
		}
		//cout << sum2 << " " << sum1 << endl;
		if(m>=sum2&&m<=sum1) puts("yes");
		else puts("no");
	}
}
