#include <iostream>
using namespace std;

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d%d",&a[i].x,&a[i].y);
			M[i].claer();
		}
		for(int i=0;i<n;i++){
			int sam=0;
			for(int j=0;j<i;j++){
				Node tmp=a[i]-a[j];
				int d=gcd(tmp.x,tmp.y);
	
			}
		}
	}
}
