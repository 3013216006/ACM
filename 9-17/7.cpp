#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
int n,m,a[100010],b[100010];
int pan(int k){
	b[0]=0;
	int l=0,r=0,r1=1;
	long long sum=0;
	while(l+1<n&&a[l+1]==0) l++;
	int xx=n-l,mytmp=k;
	if(xx>k){
		xx-=k;
		xx%=(k-1);
		xx++;
		mytmp=xx;
	}
	if(mytmp==1) mytmp=k;
	for(int i=0;i<mytmp&&l<n;i++,l++)
		b[0]+=a[l];
	sum=b[0];
	if(l==n){
		if(sum<=m) return 1;
		return 0;
	}
	while(r<r1){
		b[r1]=0;
		int tmp=k;
		while(tmp--){
			if(r<r1){
				if(l<n){
					if(a[l]<b[r]){
						b[r1]+=a[l++];
					}
					else{
						b[r1]+=b[r++];
					}
				}
				else{
					b[r1]+=b[r++];
				}
			}
			else{
				if(l<n){
					b[r1]+=a[l++];
				}
				else{
					break;
				}
			}
		}
		sum+=b[r1];
		if(sum>m) return 0;
		if(r1==r&&l==n) break;
		r1++;
	}
	if(sum<=m) return 1;
	return 0;
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++)
			scanf("%d",&a[i]);
		sort(a,a+n);
		int l=2,r=n,ans=n;
		while(l<=r){
			int mid=l+r>>1;
			if(pan(mid)) r=mid-1,ans=mid;
				else l=mid+1;
		}
		printf("%d\n",ans);
	}
}
