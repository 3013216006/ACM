#include <iostream>
#include <stdio.h>
using namespace std;
struct Node{
	int x,y;
}a[100];
int sig(int x){
	if(x>0) return 1;
	if(x<0) return -1;
	return 0;
}

int xmul(Node a,Node b,Node c){
	return (a.x-c.x)*(b.y-c.y)-(b.x-c.x)*(a.y-c.y);
}
int main(){
	int w,h;
	int l;
	while(~scanf("%d%d",&w,&h)){
		if(w==0&&h==0) break;
		scanf("%d",&l);
		for(int i=0;i<=l;i++){
			scanf("%d%d",&a[i].x,&a[i].y);
		}
		int ans=1;
		for(int i=1;i<=l;i++){
			int tmp=1;
			for(int j=1;j<i;j++){
//				cout << j << "-------"  << endl;
				if(sig(xmul(a[i],a[i-1],a[j]))*sig(xmul(a[i],a[i-1],a[j-1]))>=0) continue;
				if(sig(xmul(a[j],a[j-1],a[i]))*sig(xmul(a[j],a[j-1],a[i-1]))>=0) continue;
				tmp++;
//				cout << tmp << endl;
			}
			ans+=tmp;
//			cout << ans << endl;
		}
		cout << ans << endl;
	}
}
