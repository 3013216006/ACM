#include <iostream>
#include <stdio.h>
using namespace std;
struct point{
	int x,y;
}p[100];

int sig(int x){
	if(x>0) return 1;
	if(x<0) return -1;
	return 0;
}

int xmul(point a,point b,point c){
	return (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);
}

bool hasCross(point a1,point a2,point b1,point b2){
	if(sig(xmul(a1,a2,b1))*sig(xmul(a1,a2,b2))>=0)
		return false;
	if(sig(xmul(b1,b2,a1))*sig(xmul(b1,b2,a2))>=0)
		return false;
	return true;
}
int main(){
	int T,cas=1;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d%d",&p[i].x,&p[i].y);
		}
		int ans=0;
		for(int i=0;i<n;i++)
			for(int j=i+1;j<n;j++)
				for(int l=j+1;l<n;l++)
					for(int r=l+1;r<n;r++)
						if(hasCross(p[i],p[j],p[l],p[r])||hasCross(p[i],p[l],p[j],p[r])||hasCross(p[i],p[r],p[j],p[l]))
							ans++;
		printf("Case %d: %d\n",cas++,ans);

	}
}
