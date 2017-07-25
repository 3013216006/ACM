#include <iostream>
using namespace std;

int main(){
	int n=1000000;
	int t=20;

	while(t--){
	cout << n << endl;
	for(int i=1;i<=n;i++)
		cout << 1 << " " ;
	cout << endl;
	for(int i=1;i<=n;i++){
		cout << i << " ";
	}
	cout << endl;
	}
}
