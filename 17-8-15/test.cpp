#include <iostream>
#include <string.h>
using namespace std;

int main(){
	int a[1000];
	memset(a,0,sizeof(a));
	int ans=0;
	for(int i=2;i<=500;i++){
		if(a[i])continue;
		ans++;
		for(int j=i+i;j<=500;j+=i)
			a[j]=1;
	}
	cout << ans << endl;
}
