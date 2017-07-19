#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	if(n<m)
		for(int i=0;i<n;i++)
			if(i*i<n) cout << i << endl;
	else 
		for(int i=0;i<m;i++)
			if(i*i<m) cout << i << endl;
}
