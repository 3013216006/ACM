#include <iostream>
using namespace std;
int n,m;
void getnext(){
	_next[0]=0;
	for(int i=1;i<=m;i++){
		if(
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++)
			scanf("%d",&a[i]);
		for(int i=0;i<m;i++)
			scanf("%d",&b[i]);
		getnext(1,m);
		int t=pan(n,m);
		printf("%d\n",t);
	}
}
