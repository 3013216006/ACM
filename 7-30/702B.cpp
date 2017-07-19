#include <iostream>
#include <stdio.h>
#include <map>
#include <string.h>
using namespace std;

map<int,int>M;
int a[100100];
int main(){
	int n;
	while(~scanf("%d",&n)){
		M.clear();
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
			M[a[i]]++;
		}
		long long ans=0;
		for(int l=1;l<32;l++){
			int x=1<<l;
			for(int i=0;i<n;i++)
				if(x-a[i]==a[i])
					ans+=M[x-a[i]]-1;
				else
					ans+=M[x-a[i]];
		}
		ans/=2;
		printf("%lld\n",ans);
	}
}
