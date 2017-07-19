#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
struct Node{
	int l,r,u,d;
}ans[1010][1010];

unsigned int getans(int xx,int yy){
	unsigned int x=xx,y=yy;
	unsigned ret=1,tmp=2;
	ret=x*(x+1)/tmp*(y+1);
	ret+=y*(y+1)/tmp*x;
	return ret;	
}
int b[1010],a[1010][1010];
int main(){
	int T,n,m;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				scanf("%d",&a[i][j]);
		for(int i=0;i<n;i++){
			int l=0;
			for(int j=0;j<m;j++){
				while(l&&a[i][b[l]]>a[i][j]) l--;
				if(l==0) ans[i][j].l=j+1;
				else
				ans[i][j].l=j-b[l];
				l++;
				b[l]=j;
			}
			l=0;
			for(int j=m-1;j>=0;j--){
				while(l&&a[i][b[l]]>a[i][j]) l--;
				if(l==0) ans[i][j].r=m-j-1;
				else ans[i][j].r=b[l]-j-1;
				l++;
				b[l]=j;
			}
		}
		for(int j=0;j<n;j++){
			int l=0;
			for(int i=0;i<n;i++){
				while(l&&a[b[l]][j]<a[i][j]) l--;
				if(l==0) ans[i][j].u=i+1;
				else ans[i][j].u=i-b[l];
				l++;
				b[l]=i;
			}
			l=0;
			for(int i=n-1;i>=0;i--){
				while(l&&a[b[l]][j]<a[i][j]) l--;
				if(l==0) ans[i][j].d=n-i-1;
				else ans[i][j].d=b[l]-i-1;
				l++;
				b[l]=i;
			}
		}
		unsigned int sum=0;
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++){
				unsigned int tmp=a[i][j];
				tmp*=getans(ans[i][j].l,ans[i][j].r)*getans(ans[i][j].u,ans[i][j].d);
				sum+=tmp;
			}
		cout << sum << endl;
	}
}
