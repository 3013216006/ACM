#include <iostream>
#include <string.h>
#include <algorithm>
#include <stdio.h>
using namespace std;
struct Node{
	int l,r;
}a[100010];
bool cmp(Node a,Node b){
	return a.l<b.l;
}
int sum[100010];
int main(){
	int n,m;
	while(~scanf("%d%d",&n,&m)){
		for(int i=0;i<n;i++){
			scanf("%d%d",&a[i].l,&a[i].r);
		}
		sort(a,a+n,cmp);
		int st=1;
		memset(sum,0,sizeof(sum));
		st=a[0].r;
		sum[0]=0;
		for(int i=1;i<n;i++){
			if(a[i].l<=st+1) sum[i]=sum[i-1];
			else sum[i]=sum[i-1]+a[i].l-st-1;
			st=max(a[i].r,st);
		}
		int l=0;
		st=a[0].r;
		int ans=a[0].r-a[0].l+1+m;
		for(int i=1;i<n;i++){
			while(sum[i]-sum[l]>m){
				l++;
			}
			st=max(st,a[i].r);
			ans=max(ans,st-a[l].l+1+(m-(sum[i]-sum[l])));
		}
		cout << ans << endl;
	}
}
