#include <iostream>
#include <stdio.h>
using namespace std;

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		cout << (n-1)/2+2 << endl;
	}
}
