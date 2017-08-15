#include <iostream>
#include <stdio.h>
using namespace std;
int fa[10010];

int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}

int main(){
	int n,x;

	while(~scanf("%d",&n)){
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&x);
		int fax=find(i),fay=find(x);
		if(fax!=fay) fa[fay]=fax;
	}
	int ans=0;
	for(int i=1;i<=n;i++)
		if(fa[i]==i) ans++;
	cout << ans << endl;
	}
}
