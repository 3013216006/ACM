#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

long long h[100],b[100];

int main(){
	memset(h,0,sizeof(h));
	memset(b,0,sizeof(b));
	h[0]=2;
	h[1]=3;
	h[2]=6;
	for(int i=3;i<=30;i++)
		h[i]=4*h[i-1]+17*h[i-2]-12*h[i-3]-16;
	for(int i=1;i<=30;i++)
		b[i]=3*h[i+1]*h[i]+9*h[i+1]*h[i-1]+9*h[i]*h[i]+27*h[i]*h[i-1]-18*h[i+1]-126*h[i]-81*h[i-1]+192;
	for(int i=1;i<=30;i++)
		cout << h[i] <<  " " << (1ll<<i) << endl;
		
}
