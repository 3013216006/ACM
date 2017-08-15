#include <iostream>
#include <stdio.h>
using namespace std;

int main(){
	int n,k;
	while(~scanf("%d%d",&n,&k)){
		if(n==4){
			if(k==3){
				cout << n-1 << endl;
				for(int i=1;i<n;i++)
					cout << i << " " << i+1 << endl;
			}
			else{
				puts("-1");
			}
		}
		else
		if(n==3){
			if(k==1){
				cout << 1 << endl;
				cout << 1 << " " << 2 << endl;
			}
			else
			cout << -1 << endl;
		}
		else
		if(k==2){
			if(n<=3){
				cout << -1 << endl;
			}
			else {
				cout << n-1 << endl;
				for(int i=1;i<n;i++)
					cout << i << " " << i+1 << endl;
			}
		}
		else{
			puts("-1");
		}
	}
}
