#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
long long a[1000100],b[1000100];
long long c[1000100];
int d[1000100];
int myget(int l,int r,int x){
	if(x<a[l]) return 0;
	int ret=l;
	while(l<=r){
		int mid=l+r>>1;
		if(a[mid]<=x) ret=mid,l=mid+1;
			else r=mid-1;
	}
	return ret;
}

int main(){
	int n,m;
	while(~scanf("%d",&n)){
		for(int i=0;i<n;i++){
			scanf("%lld",&a[i]);
			if(i) a[i]+=a[i-1];
		}
		memset(b,0,sizeof(b));
		int l=0;
		while(a[l]<0) l++;
		b[l+1]=1;
		d[1]=l+1;
		int x=1;
		c[x]=a[l];
		for(int i=l+1;i<n;i++)
			if(a[i]>=0){
				int r=myget(1,x,a[i]);
				cout << d[r] << endl;
				b[i+1]=b[d[r]]+1;
				r++;
				c[r]=a[i];
				d[r]=i+1;
				x=max(x,r);
			}
		cout << b[n] << endl;
	}
}
