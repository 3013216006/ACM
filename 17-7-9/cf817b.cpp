#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
int a[100020];

int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	sort(a,a+n);
	int l=1;
	while(2+l<n&&a[2]==a[2+l])l++;
	int k=1;
	if(a[1]==a[2]) k++,l++;
	if(a[0]==a[2]) k++,l++;
	long long ans=1;
	for(int i=0;i<k;i++)
		ans*=(l-i);
	for(int i=0;i<k;i++)
		ans/=(i+1);
	cout << ans << endl;
}
