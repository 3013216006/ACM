#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
int a[100000];

long long init(){
	for(long long i=1;;i++){
		a[i]=i*i*2;
		if(a[i]>1000000000ll) return i;
	}
}

int main(){
	int T;
	long long l=init();
	int n;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		long long x=lower_bound(a+1,a+l,n)-a;
		int ans=0;
		if(n>x*(x-1)*2){
			if(n>x*(x+x-1)-1) ans=x*4;
			else ans=x*4-1;
		}
		else{
			if(n>(x-1)*(x+x-1)-1) ans=x*4-2;
			else ans=x*4-3;
		}
		cout << ans << endl;
	}
}
