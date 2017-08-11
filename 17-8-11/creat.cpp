#include <iostream>
#include <stdio.h>

using namespace std;

int main(){
	int x;
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++){
			scanf("%d",&x);
			cout << "b[" << i << "][" << j << "]=" << x<< ";\n" ;
		}
}
