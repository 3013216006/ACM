#include <iostream>
#include <stdio.h>
using namespace std;

int main(){
	int T;
	int n;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		long long l,r;
		l=r=n;
		int tmp=1;
		while(n%2==0) tmp<<=1,n>>=1;
		tmp/=2;
		while(tmp){
			l-=tmp;
			r+=tmp;
			tmp/=2;
		}
		cout << l << " " << r << endl;
	}
}
