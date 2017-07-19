#include <iostream>
#include <stdio.h>
using namespace std;
int x[1000000],y[1000000],l1[1000000],r1[1000000],r2[1000000],l2[1000000];
int a[1000000];

int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	int l=0;
	y[0]=-1;
	for(int i=0;i<n;i++){
		while(l&&a[i]>=x[l]) l--;
		l++;
		x[l]=a[i];
		y[l]=i;
		l1[i]=i-y[l-1];
	}
	l=0;
	for(int i=0;i<n;i++){
		while(l&&a[i]<=x[l]){
			l--;
		}
		l++;
		x[l]=a[i];
		y[l]=i;
		l2[i]=i-y[l-1];
	}
	l=0;
	y[0]=n;
	for(int i=n-1;i>=0;i--){
		while(l&&a[i]>x[l]) l--;
		l++;
		x[l]=a[i];
		y[l]=i;
		r1[i]=y[l-1]-i;
	}
	l=0;
	for(int i=n-1;i>=0;i--){
		while(l&&a[i]<x[l]) l--;
		l++;
		x[l]=a[i];
		y[l]=i;
		r2[i]=y[l-1]-i;
	}
	long long ans=0;
	for(int i=0;i<n;i++){
		ans+=1ll*l1[i]*r1[i]*a[i];
		ans-=1ll*l2[i]*r2[i]*a[i];
	}
	cout << ans << endl;
}
