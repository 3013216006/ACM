#include <iostream>
using namespace std;

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++){
			scanf("%d%d",&a[i].x,&a[i].y);
		}
		for(int i=0;i<m;i++){
			scanf("%d%d%d",&b[i].x,&b[i].y,&b[i].z);
		}
		sort(a,a+n,cmp);
		memset(m,0,sizeof(m));
		memset(count,0,sizeof(count));


	}
}
