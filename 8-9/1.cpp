#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
int num[100100],a[100100];
int main(){
	int n;
	while(~scanf("%d",&n)){
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		int ans=0;
		memset(num,-1,sizeof(num));
		for(int i=0;i<n-ans;i++){
			int r=0;
			for(int j=i;j<n;j++){
				if(num[a[j]]==i) break;
				num[a[j]]=i;
				while(num[r+1]==i) r++;
				if(r==j-i+1) ans=max(r,ans);
			}
		}
		cout << ans << endl;
	}
}
