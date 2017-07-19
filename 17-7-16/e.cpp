#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
struct Node{
	double x,y;
}a[100010];
int cnt;
void add(double x,double y){
	a[cnt].x=x;
	a[cnt++].y=y;
}
bool cmp(Node a,Node b){
	return a.y<b.y;
}
int main(){
	int T,cas=1;
	int n,m,ax,ay,az,bx,by,bz;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		 cnt=0;
		for(int i=0;i<n;i++){
			scanf("%d%d%d%d%d%d",&ax,&ay,&az,&bx,&by,&bz);
			long long A=1ll*bx*bx+1ll*by*by+1ll*bz*bz,B=1ll*2*ax*bx+1ll*2*ay*by+1ll*2*az*bz,C=1ll*ax*ax+1ll*ay*ay+1ll*az*az-1ll*m*m;
			if(B*B-4*A*C<0)  continue;
			else{
				double tmp=sqrt(1.0*B*B-4*A*C);
				double t1=(-B+tmp)/(2*A),t2=(-B-tmp)/(2*A);
				if(t1<-1e-8) continue;
				add(t2,t1);
			}
		}
		sort(a,a+cnt,cmp);
		int ans=0;

		//for(int i=0;i<cnt;i++)
			//cout << a[i].x << " " << a[i].y << endl;
		for(int i=0;i<cnt;i++){
			double tmp=a[i].y;
			ans++;
			while(i<cnt&&a[i+1].x<tmp+1e-8){
				i++;
			}
		}
		printf("Case %d: %d %d\n",cas++,cnt,ans);
	}
}
