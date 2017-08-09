#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
char s[111][111];

int main(){
	int n,m;
	while(~scanf("%d%d",&n,&m)){
		for(int i=0;i<n;i++)
			scanf("%s",s[i]);
		int x=-1,y=-1,xx=n,yy=m,sum=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(s[i][j]=='B'){
					x=max(i,x);
					y=max(j,y);
					xx=min(xx,i);
					yy=min(yy,j);
					sum++;
				}
			}
		}
		if(sum==0){
			printf("%d\n",1);
		}
		else{
			int ans=-1;
			int l=max(x-xx,y-yy)+1;
			if(l<=n&&l<=m) ans=l*l-sum;
			cout << ans << endl;
		}
	}
}
