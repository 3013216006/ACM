#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
	int T;
	int n,m;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		int x=(m-n*2)/2;
		int y=n-x;
		cout << x << " " << y << endl;
	}
}
