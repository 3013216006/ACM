#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int a[100100];
int main(){
	int n;
	while(~scanf("%d",&n)){
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		for(int i=1;i<=n;i++){
			if(a[i]>a[i%n+1]&&a[i]>a[(i-2+n)%n+1]){
				cout << (i-2+n)%n+1 << " " << i << " " <<  i%n+1 << endl;
				break;
			}
		}
	}
}
