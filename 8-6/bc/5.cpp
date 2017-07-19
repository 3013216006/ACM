#include <iostream>
#include <stdio.h>
using namespace std;
int a[100000];

int abs(int x){
	if(x<0) return -x;
	return x;
}
int n;
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			scanf("%d",&a[i]);
		long long ans=0;
		for(int i=0;i<n;i++){
			int pre=-1,tmp=0;
			for(int j=0;j<n;j++){
				if(i==j) continue;
				if(pre!=-1) tmp=max(tmp,abs(pre-a[j]));
				pre=a[j];	
			}
			ans+=tmp;
		}
		cout << ans << endl;
	}
}
