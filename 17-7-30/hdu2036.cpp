#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
struct Node{
	long long x,y;
}a[110],p;

long long xmul(Node a,Node b,Node c){
	return (a.x-c.x)*(b.y-c.y)-(a.y-c.y)*(b.x-c.x);
}
int main(){
	int n;

	while(scanf("%d",&n),n){
		for(int i=0;i<n;i++){
			scanf("%lld%lld",&a[i].x,&a[i].y);
		}
		long long ans=0;
		for(int i=0;i<n;i++){
			ans+=xmul(a[i],a[(i+1)%n],p);
		}
		if(ans%2){
			cout << ans/2 << ".5" << endl; 
		}
		else{
			cout << ans/2 << ".0" << endl;
		}
	}
}
