#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
int a[100100],ans[100100];
int main(){
	int T,n,x;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		int l=0;
		for(int i=0;i<n;i++){
			scanf("%d",&x);
			int tmp=l;
			if(tmp){
				tmp=lower_bound(a+1,a+l+1,x)-a;
			}
			while(tmp&&a[tmp]>=x) tmp--;
			tmp=min(tmp,l);
			tmp++;
			a[tmp]=x;
			ans[i]=tmp;
			l=max(l,tmp);
		}
		for(int i=0;i<n;i++){
			if(i) printf(" ");
			printf("%d",ans[i]);
		}
		printf("\n");
	}
}
