#include <iostream>
#include <map>
#include <stdio.h>
using namespace std;
int a[100100];
map<long long,int> M;
int main(){
	int n;
	while(~scanf("%d",&n)){
		long long x=0;
		for(int i =0;i<n;i++){
			scanf("%d",&a[i]);
			x+=a[i];
		}
		if(x%2){
			puts("NO");
			continue;
		}
		M.clear();
		x/=2;
		long long sum=0;
		int flag=0;
		for(int i=0;i<n;i++){
			M[a[i]]=1;
			sum+=a[i];
			if(sum==x){
				flag=1;
				break;
			}
			if(M.count(sum-x)>0){
				flag=1;
				break;
			}
		}
		M.clear();
		sum=0;
		for(int i=n-1;i>=0;i--){
			M[a[i]]=1;
			sum+=a[i];
			if(sum==0){
				flag=1;
				break;
			}
			if(M.count(sum-x)>0){
				flag=1;
				break;
			}
		}
		if(flag) puts("YES");
		else puts("NO");
	}
}
