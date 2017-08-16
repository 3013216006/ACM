#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

long long l,r,w;

int main(){
	while(cin >> l >> r >> w){
		long long d=__gcd(w,r);
		if(r+w<=l+d) puts("OK");
		else{puts("DEADLOCK");
		}
	}
}
