#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int b[2000100],a[2000100];
char s[100];
double ans[1000100];

int main(){
	int n;
	while(~scanf("%d",&n)){
		for(int i=0;i<n*2;i++){
			scanf("%s%d",s,&b[i]);
			if(s[0]=='-') a[i]=1;
			else a[i]=0;
		}
		int num=0;
		double sum=0;
		int l=0;
		for(int i=n*2-1;i>=0;i--){
			if(a[i]) sum+=b[i],num++;
			else{
				ans[l++]=sum/num-b[i];
				sum=sum*(num-1)/num;
				num--;
			}
		}
		for(int i=l-1;i>=0;i--)
			printf("%.8f\n",ans[i]);
	}
}
