#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int num[100100],a[100100];
int main(){
	int n;
	while(~scanf("%d",&n)){
		memset(num,0,sizeof(num));
		int ans=0,l=0;
		int m=0,r=0;
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
			num[a[i]]++;
			while(num[a[i]]==2){
				num[a[l]]--;
				//if(a[l-1]==a[i]) break;
				if(a[l]<=r&&num[a[l]]==0) r=a[l];
				while(r>0&&num[r]==0) r--; 
				l++;
			}
			while(num[r+1]) r++;
			if(r==l-i)
			ans=max(r,ans);
		}
		cout << ans << endl;
	}
}
