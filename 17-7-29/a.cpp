#include <iostream>
#include <stdio.h>
#include <set>
#include <string.h>
using namespace std;
set<int> s;
int main(){
	s.clear();
	int n,x;
	n=1000000000;
	for(int i=0;i*i<=n;i++){
		s.insert(i*i);
	}
	while(~scanf("%d",&n)){
		int flag=1;
		for(int i=0;i<n;i++){
			scanf("%d",&x);
			if(s.count(x)>0) ;
			else flag=0;
		}
		if(flag) puts("Yes");
		else puts("No");
	}
}
