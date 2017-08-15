#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

int main(){
	cout << 1 << endl;
	int n=2*100000;
	cout << n  << " " << 1000000000 << endl;
	for(int i=0;i<n;i++)
		cout << rand() << endl;
}
