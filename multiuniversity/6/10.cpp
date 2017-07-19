#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int a[50];
void init(){
	a[0]=1;
	for(int i=1;i<31;i++)
		a[i]=a[i-1]+(1<<i);
}
int n,m;
int dfs(int x){
	int d=n-m;
	int i=lower_bound(a,a+31,d)-a;
	int tmp=max(0,n-a[i]);
	if(tmp==m) return i+1+x;
	int ret=i+1+max(m-tmp,x);
	n-=a[i-1];
	return min(ret,dfs(x+1)+i);

}

int main(){
	init();
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		if(n<=m){
			printf("%d\n",m-n);
		}
		else printf("%d\n",dfs(0));
	}
}
