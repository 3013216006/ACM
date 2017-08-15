#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
struct Node{
	int x,y,z,op;
}a[150010];
int cnt;

void add(int x,int y,int z,int op){
	a[cnt].x=x;
	a[cnt].y=y;
	a[cnt].z=z;
	a[cnt].op=op;
	cnt++;
}

bool cmp(Node a,Node b){
	if(1ll*a.x*b.x<=0) return a.x>b.x;
	else return 1ll*a.x*b.y>1ll*b.x*a.y;
}

int main(){
	int T;
	int x,y,z,tmp;
	int n;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		cnt=0;
		int flag=0;
		long long sum1=0,sum2=0;
		for(int i=0;i<n;i++){
			scanf("%d%d%d",&x,&y,&z);
			if(y==0) flag=x,tmp=z;
			else{
				if(y<0) add(-x,-y,z,1),sum1+=z;
				else add(x,y,z,0),sum2+=z;
			}
		}
		sort(a,a+cnt,cmp);
		long long ans=0;
		if(flag) ans=max(sum1*(sum2+tmp),sum2*(sum1+tmp));
			else ans=sum1*sum2;
		if(flag<0) sum2+=tmp;
		else if(flag>0) sum1+=tmp;
		for(int i=0;i<cnt;i++){
			if(a[i].op==1) sum1-=a[i].z,sum2+=a[i].z;
			else sum1+=a[i].z,sum2-=a[i].z;
			ans=max(ans,sum1*sum2);
		}
		cout << ans << endl;
	}
}
