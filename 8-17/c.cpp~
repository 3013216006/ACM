#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
int abs(int x){
	if(x<0) return -x;
		else return x;
}
int main(){
	int n,m;
	while(1){
		int x,y;
		x=rand()%10000000;
		y=rand()%10000000;
		int ans=0;
		while(scanf("%d",&n)){
			if(n<0){
				cout << x << " " << y << endl;
			}
			scanf("%d",&m);
			int tmp=abs(x-n)+abs(y-m);
			if(tmp<=ans) cout << 0 << endl;
				else cout << 1 << endl;
			ans=tmp;
		}
	}
}
