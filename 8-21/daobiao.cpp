#include <iostream>
using namespace std;

int main(){
	for(int i=1;i<=10;i++){
		cout << i << endl;
		for(int j=0;j<i;j++){
			cout << j << " " << i-j-1<< endl;
		}
	}
}

