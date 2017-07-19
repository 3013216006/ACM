#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int a[55];

int main(){
	int T,cas=1,n,l,r;
	scanf("%d",&T);
	while(T--){
		for(int i=1;i<=52;i++)
			scanf("%d",&a[i]);
		scanf("%d%d%d",&n,&l,&r);
		int st=(r-l+1)*(n%r)%r;
		st=r-st+1;
		int flag=0;
		printf("Case #%d:",cas++);
		for(int i=st;i<=r;i++){
			printf(" %d",a[i]);
		}
		for(int i=1;i<st;i++){
			printf(" %d",a[i]);
		}
		for(int i=r+1;i<=52;i++){
			printf(" %d",a[i]);
		}
		puts("");
	}
}
