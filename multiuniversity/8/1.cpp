#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
int a[1010],b[1010];
int main(){
	int T,n,m,l,r;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		for(int i=0;i<n;i++){
			scanf("%d",&b[i]);
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++)
				if(a[i]==b[j]){
					a[i]=j,b[j]=-1;
					break;
				}
		}
		for(int i=0;i<m;i++){
			scanf("%d%d",&l,&r);
			int tmp=a[r];
			sort(a+l-1,a+r);
			a[r]=tmp;
		}
		int flag=1;
		for(int i=0;i<n;i++)
			if(a[i]!=i) flag=0;
		if(flag) puts("Yes");
			else puts("No");
	}
}
