#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
struct Node{
	long long x,y;
}a[110];

long long dmul(Node a,Node b,Node c){
	return (a.x-c.x)*(b.x-c.x)+(a.y-c.y)*(b.y-c.y);
}
long long xmul(Node a,Node b,Node c){
	return (a.x-c.x)*(b.y-c.y)-(a.y-c.y)*(b.x-c.x);
}

int pan(int i,int j,int k){
	if(dmul(a[i],a[j],a[k])<0) return 0;
	if(xmul(a[i],a[j],a[k])==0) return 0;
	if(dmul(a[i],a[k],a[j])<0) return 0;
	if(dmul(a[j],a[k],a[i])<0) return 0;
	return 1;
}

int main(){
	int T,n;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%I64d%I64d",&a[i].x,&a[i].y);
		}
		int ans=0;
		for(int i=0;i<n;i++)
			for(int j=i+1;j<n;j++)
				for(int k=j+1;k<n;k++)
					if(pan(i,j,k)) ans++;
		cout << ans << endl;
	}
}
