#include <iostream>
#include <stdio.h>
using namespace std;

int main(){
	int n,k,x;
	while(~scanf("%d%d",&n,&k)){
		int ans1=n,ans2=2*n;
		int xx=0;
		for(int i=0;i<k;i++){
			scanf("%d",&x);
			if(x>=ans1*4){
				x-=ans1*4;
				ans1=0;
				ans2-=(x/2+x%2);
				xx+=x%2;
			}
			else{
				ans1-=x/4;
				x=x-x/4*4;
				ans2-=(x/2+x%2);
				xx+=x%2;
			}
		}
//		cout << ans2 << " " << ans1 << endl;
		if((ans2+xx*2>=0&&(-ans2)/2+(-ans2)%2<=ans1)||(ans2+xx+ans1>=0&&xx<=ans1)||(xx>=ans1&&2*xx<=ans1&&(-ans2)/2+(-ans2)%2<=ans1)||(xx<=ans1&&(-ans2-xx*2)/3*2+(-ans2-xx*2)%3+xx<=ans1)) puts("YES");
		else puts("NO");
	}
}
