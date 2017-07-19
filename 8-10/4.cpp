#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
int a[1001];
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		for(int i=0;i<5;i++)
		scanf("%d",&a[i]);
		sort(a,a+5);
		long long ans=(long long)a[4]*a[3];
		cout << ans << endl;
	}
}
