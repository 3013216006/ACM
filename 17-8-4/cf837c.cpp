#include <iostream>
#include <stdio.h>
using namespace std;
int n,m,k;
int x[110],y[110];

bool _is(int x,int y,int xx,int yy){
	if(x+xx<=n&&y<=m&&yy<=m) return true;
	if(y+yy<=m&&x<=n&&xx<=n) return true;
	swap(x,y);
	if(x+xx<=n&&y<=m&&yy<=m) return true;
	if(y+yy<=m&&x<=n&&xx<=n) return true;
	swap(x,y);
	swap(xx,yy);
	if(x+xx<=n&&y<=m&&yy<=m) return true;
	if(y+yy<=m&&x<=n&&xx<=n) return true;
	swap(x,y);
	if(x+xx<=n&&y<=m&&yy<=m) return true;
	if(y+yy<=m&&x<=n&&xx<=n) return true;
	return false;
	
	
}

int main(){
	while(~scanf("%d%d%d",&k,&n,&m)){
		for(int i=0;i<k;i++){
			scanf("%d%d",&x[i],&y[i]);
		}
		int ans=0;
		for(int i=0;i<k;i++){
			for(int j=i+1;j<k;j++){
				if(_is(x[i],y[i],x[j],y[j])) ans=max(ans,x[i]*y[i]+x[j]*y[j]);
			}
		}
		cout << ans << endl;
	}
}
