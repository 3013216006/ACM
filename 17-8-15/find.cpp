#include <iostream>
#include <bitset>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
bitset<16> A[64];
int main(){
	for(int i=0;i<16;i++){
		A[i].reset();
		A[i][15-i]=1;
	}
	for(int i=1;i<=100;i++){
		printf("round %d\n",i);
		for(int j=1;j<16;j++)
			A[j]^=A[j-1];
		for(int j=0;j<16;j++)
			cout << A[j] << endl;
	}
}
