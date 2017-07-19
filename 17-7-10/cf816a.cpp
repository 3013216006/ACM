#include <iostream>
#include <stdio.h>
using namespace std;
int A[30];
void init(){
	for(int i=0;i<=23;i++){
		int x=i%10;
		int y=i/10;
		A[i]=x*10+y;
	}
}
int main(){
	init();
	int a,b;
	int ans;
	while(~scanf("%d:%d",&a,&b)){
		if(b<=A[a]) ans=A[a]-b;
		else{
			ans=60-b;
			a++;
			a%=24;
			while(A[a]>=10) {
				a++; ans+=60;
			}
			ans+=A[a];
		}
		cout << ans << endl;
	}
}
