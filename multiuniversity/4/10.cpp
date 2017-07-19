#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
int a[100100],b[100100];
int main(){
	int T,cas=1;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			scanf("%d",&a[i]);
		int l1=0,r1=n-1;
		while(l1<n&&a[l1]==0) l1++;
		while(r1>l1&&a[r1]==0) r1--;
		int ans=0,l=0;
		b[0]=0;
		for(int i=l1;i<=r1;i++){
		if(a[i]==0){
			if(l==0){
				b[1]=0;
				l=1;
				continue;
			}
			int tmp=l;
			while(tmp>=1){
		//		if(b[tmp]==1000000){
		//			tmp--;
		//			continue;
		//		}
				b[tmp+1]=b[tmp]+1;
				if(b[tmp]==tmp-1) break;
				tmp--;
			}
		//	if(b[l]!=1000000) l++;
		l++;
			b[1]=0;
			
		}
		else{
			if(l==0){
				l=1;
				b[l]=a[i];
				continue;
			}
			int r=lower_bound(b+1,b+l,a[i])-b;
			//r--;
			while(b[r]>=a[i]&&r>0) r--;
			r++;
			b[r]=a[i];
			if(r==l+1) l++;
		}
		}
		ans=l+l1+(n-1-r1);
		printf("Case #%d: %d\n",cas++,ans);
	}
}
